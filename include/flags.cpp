#ifndef FLAGS_CPP
#define FLAGS_CPP
#include <iostream>

// Dont hate on me for using a macro for this...
// I like it because its easy to modify okay...
#define FLAG_IS_F static_cast<std::string>(argv[i]) == "-f" || static_cast<std::string>(argv[i]) == "--file"
#define FLAG_IS_C static_cast<std::string>(argv[i]) == "-c" || static_cast<std::string>(argv[i]) == "--console"
#define FLAG_IS_H static_cast<std::string>(argv[i]) == "-h" || static_cast<std::string>(argv[i])  == "--help"

namespace flag {
    enum type {
        FILE,
        HELP,
        CONSOLE,
    };
    struct flag {
        type _type;
        std::string _value{};
        flag(type type, std::string value) : _type(type), _value(value) {}
    };

    std::vector<flag> parse(int argc, char *argv[]) {
        // No Flags Present
        if (argc < 1){return {};}

        std::vector<flag> flags;
        for(int i = 1; i < argc; i++) {
            if(FLAG_IS_H) {
                std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
            }
            else if (FLAG_IS_F) {
                flag file_flag(FILE, argv[i+1]);
                flags.push_back(file_flag);
            }
            else if (FLAG_IS_C) {
                flag console_flag(CONSOLE, "");
                flags.push_back(console_flag);
            }
        }
        return flags;
    }

    // check if any flags indicate console move
    bool isInConsoleMode(std::vector<flag> flags) {
        for(auto& flag : flags) {
            if(flag._type == CONSOLE) {
                return true;
            }
        }
        return false;
    }

}
#endif