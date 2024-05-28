#include <iostream>
#include <string>
#include <vector>
#include <ctime>

// Call class to represent a telephone call
class Call {
public:
    std::string callerID;
    std::string receiverID;
    std::string timestamp;

    Call(const std::string& caller, const std::string& receiver) 
        : callerID(caller), receiverID(receiver) {
        // Get current time
        std::time_t now = std::time(nullptr);
        timestamp = std::ctime(&now);
        timestamp.pop_back(); // Remove trailing newline
    }
};

// CTI class to manage calls
class CTI {
private:
    std::vector<Call> callLog;

public:
    void makeCall(const std::string& caller, const std::string& receiver) {
        Call newCall(caller, receiver);
        callLog.push_back(newCall);
        std::cout << "Call made from " << caller << " to " << receiver << " at " << newCall.timestamp << "\n";
    }

    void receiveCall(const std::string& caller, const std::string& receiver) {
        Call newCall(caller, receiver);
        callLog.push_back(newCall);
        std::cout << "Call received from " << caller << " to " << receiver << " at " << newCall.timestamp << "\n";
    }

    void showCallLog() const {
        std::cout << "\nCall Log:\n";
        for (const auto& call : callLog) {
            std::cout << "Caller: " << call.callerID << ", Receiver: " << call.receiverID << ", Time: " << call.timestamp << "\n";
        }
    }
};

int main() {
    CTI cti;
    int choice;
    std::string caller, receiver;

    do {
        std::cout << "\nCTI Menu:\n";
        std::cout << "1. Make a call\n";
        std::cout << "2. Receive a call\n";
        std::cout << "3. Show call log\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter caller ID: ";
            std::cin >> caller;
            std::cout << "Enter receiver ID: ";
            std::cin >> receiver;
            cti.makeCall(caller, receiver);
            break;
        case 2:
            std::cout << "Enter caller ID: ";
            std::cin >> caller;
            std::cout << "Enter receiver ID: ";
            std::cin >> receiver;
            cti.receiveCall(caller, receiver);
            break;
        case 3:
            cti.showCallLog();
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

