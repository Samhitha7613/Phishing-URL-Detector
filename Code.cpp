#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> trusted_domains = {"paypal.com", "google.com", "facebook.com", "amazon.com", "microsoft.com"};


bool is_ip_address(const string& url) {
    regex ip_pattern("^(http[s]?://)?(\\d{1,3}\\.){3}\\d{1,3}");
    return regex_search(url, ip_pattern);
}


bool has_suspicious_symbols(const string& url) {
    return (url.find("@") != string::npos || url.find("-") != string::npos);
}


bool too_many_subdomains(const string& url) {
    int count = 0;
    for (char c : url) {
        if (c == '.') count++;
    }
    return count > 3; 
}

// Levenshtein Distance
int levenshtein_distance(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min({dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + cost});
        }
    }
    return dp[m][n];
}


string looks_like_typosquatting(const string& domain) {
    for (auto& trusted : trusted_domains) {
        if (levenshtein_distance(domain, trusted) <= 2) {
            return "⚠️ Looks similar to " + trusted + " (possible typosquatting)";
        }
    }
    return "";
}

// Analyze url
void analyze_url(const string& url) {
    cout << "\n🔎 Analyzing: " << url << endl;
    vector<string> issues;

    if (is_ip_address(url)) issues.push_back("❌ URL uses IP address instead of domain");
    if (has_suspicious_symbols(url)) issues.push_back("❌ Contains suspicious characters (@ or -)");
    if (too_many_subdomains(url)) issues.push_back("❌ Too many subdomains (might be phishing)");

    string typo_warning = looks_like_typosquatting(url);
    if (!typo_warning.empty()) issues.push_back(typo_warning);

    if (issues.empty())
        cout << "✅ URL looks safe" << endl;
    else {
        for (auto& issue : issues) cout << issue << endl;
    }
}

int main() {
    string url;
    char choice;

    cout << "🛡️ Phishing URL Detector (C++)" << endl;

    do {
        cout << "\nEnter a URL or IP to analyze: ";
        cin >> url;

        analyze_url(url);

        cout << "\nDo you want to check another URL? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nExiting... Stay safe online! 🛡️" << endl;
    return 0;
}
