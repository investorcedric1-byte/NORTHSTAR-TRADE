// Demo-only C++17 HTTP API. This does not connect to a broker or execute trades.
// Dependency: cpp-httplib single header (httplib.h) placed in src/.
#include <iostream>
#include <string>
#include "httplib.h"

int main() {
    httplib::Server server;

    server.Get("/api/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(R"({"status":"ok","mode":"demo"})", "application/json");
    });

    server.Get("/api/quote", [](const httplib::Request& req, httplib::Response& res) {
        const std::string symbol = req.has_param("symbol") ? req.get_param_value("symbol") : "BTCUSD";
        std::string price;
        if (symbol == "BTCUSD") price = "67420.50";
        else if (symbol == "XAUUSD") price = "2738.20";
        else if (symbol == "EURUSD") price = "1.08420";
        else if (symbol == "AAPL") price = "231.50";
        else {
            res.status = 400;
            res.set_content(R"({"error":"unsupported symbol"})", "application/json");
            return;
        }
        res.set_content("{\"symbol\":\"" + symbol + "\",\"price\":" + price +
                        ",\"mode\":\"demo\"}", "application/json");
    });

    std::cout << "Demo API listening on http://127.0.0.1:8080\n";
    server.listen("127.0.0.1", 8080);
}
