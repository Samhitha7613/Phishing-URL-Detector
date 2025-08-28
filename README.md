# 🛡️ Phishing URL Detector (C++)

![Phishing](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B) ![Status](https://img.shields.io/badge/Status-Completed-green)

A beginner-friendly yet professional **Phishing URL Detector** built in **C++** that identifies suspicious URLs and potential phishing attacks.  
This tool demonstrates practical cybersecurity skills, including **pattern recognition, typosquatting detection, and URL analysis**, making it a recruiter-friendly project for your portfolio.

---

## 🚀 Features

- **Detect IP-based URLs:** Flags URLs using raw IP addresses instead of domains (common in phishing).  
- **Suspicious Character Detection:** Identifies `@` and `-` symbols often used in phishing URLs.  
- **Subdomain Analysis:** Detects excessive subdomains to identify deceptive URLs.  
- **Typosquatting Detection:** Uses **Levenshtein Distance** to flag domains similar to trusted ones (e.g., `paypa1.com` vs `paypal.com`).  
- **Interactive Scanner:** Users can input URLs/IPs for real-time analysis.  
- **Recruiter-Friendly:** Demonstrates understanding of phishing defense, URL security, and algorithmic thinking.

---

## 🖥️ Tech Stack

- **Language:** C++  
- **Libraries:** `<iostream>`, `<string>`, `<vector>`, `<regex>`, `<algorithm>`  
- **Algorithms:** Levenshtein Distance (edit distance)  

---

## 📂 How to Use

### 1. Clone the repository:

```bash
git clone https://github.com/Samhitha7613/Phishing-URL-Detector.git
cd Phishing-URL-Detector

```
## 2. Compile the program

```bash
g++ phishing_detector.cpp -o phishing_detector
```
## 3. Run the program

```bash
./phishing_detector
```
## 4. Enter URLs or IPs to analyze
```bash
Example: Enter a URL or IP to analyze: http://paypa1.com/login
```

### he tool will display warnings or confirm that the URL looks safe.

## Example Output

```bash
🔎 Analyzing: http://paypa1.com/login
❌ Contains suspicious characters (@ or -)
⚠️ Looks similar to paypal.com (possible typosquatting)

🔎 Analyzing: https://paypal.com
✅ URL looks safe
```

## Why This Project Matters

- Showcases real-world cybersecurity awareness by detecting phishing URLs.  
- Demonstrates algorithmic thinking with Levenshtein Distance for typosquatting detection.  
- Ideal for portfolio projects or CVs for cybersecurity roles.  
- Beginner-friendly, yet recruiter-ready.  

##  Future Improvements

- Integrate with Google Safe Browsing API for live threat intelligence.  
- Build a GUI version with Qt or other C++ frameworks for a polished user interface.  
- Extend to bulk URL scanning with CSV input support.  
- Add machine learning models for advanced phishing detection.

  # 📌 **GitHub Repository**

[Phishing URL Detector – Samhitha7613](https://github.com/Samhitha7613/Phishing-URL-Detector.git)






