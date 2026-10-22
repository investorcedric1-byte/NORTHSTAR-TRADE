# Northstar Trade (Demo Starter)

A GitHub-ready, responsive multi-market trading dashboard built with HTML, CSS, and JavaScript, plus an optional C++17 API example.

## Included
- BTCUSD, XAUUSD, EURUSD, and AAPL demo symbols
- Simulated chart and quotes
- Demo buy/long and sell/short orders
- Demo position list and simulated P/L
- Basic stop-loss and take-profit price validation
- Optional C++ HTTP API sample

## Run the website with GitHub Pages
1. Create a new repository on GitHub.
2. Upload `public/index.html` and the other project files.
3. In the repository, open **Settings → Pages**.
4. Under **Build and deployment**, select **Deploy from a branch**.
5. Select branch `main` and folder `/public` (or move `index.html` to the repository root and select `/(root)`).
6. Save, then wait for GitHub Pages to publish the site.

You can also open `public/index.html` directly in your browser. No build step is required for the frontend.

## Run the C++ API locally (optional)
The website works without this API; the C++ example is a separate starter.

1. Install a C++17 compiler.
2. Obtain `httplib.h` from the official cpp-httplib project and place it in `src/`.
3. Compile on Linux:
   ```bash
   g++ -std=c++17 -O2 -pthread -Isrc src/server.cpp -o trading-api
   ```
4. Run:
   ```bash
   ./trading-api
   ```
5. Test:
   - `http://127.0.0.1:8080/api/health`
   - `http://127.0.0.1:8080/api/quote?symbol=BTCUSD`

## Important limitation
This is a **demo**, not a real broker-connected platform. All displayed prices and orders are simulated in the browser. The C++ endpoints return fixed example quotes. It does not accept deposits, hold funds, authenticate users, or send orders to a broker.

GitHub Pages hosts static websites only; it cannot run the C++ backend. To use a backend online, deploy it separately to a secure server or suitable hosting platform.

## Before enabling real trading
- Select a broker whose official API and customer-account model permit your intended use.
- Implement broker authentication and order placement on the server, never in browser code.
- Add secure login, authorization, database persistence, encryption, request idempotency, rate limiting, monitoring, audit logs, and broker reconciliation.
- Validate live account permissions, market-data licensing, margin rules, partial fills, rejects, and outages.
- Review applicable financial-services regulations and licensing requirements before onboarding customers or handling funds.
- Test in broker paper-trading/sandbox mode before any live release.

## Suggested architecture
Browser (GitHub Pages or other static hosting)
  -> HTTPS API gateway
  -> authenticated backend services
  -> database + risk engine
  -> broker-specific adapter(s)
