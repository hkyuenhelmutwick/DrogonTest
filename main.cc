#include <drogon/drogon.h>

int main()
{
    // Set the number of threads
    drogon::app().setThreadNum(16);
    
    // Set the HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 8080);
    
    // Load config file
    //drogon::app().loadConfigFile("config.json");
    
    // Register a simple handler
    drogon::app().registerHandler(
        "/",
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Hello, World!");
            callback(resp);
        });
    
    // Start the server
    drogon::app().run();
    return 0;
} 