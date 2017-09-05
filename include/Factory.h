// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description
# include <iostream>
# include <stdio.h>
# include <string>
# include <memory>

// Declare enum corresponding to different lure types
enum lureTypes {JIG, SPINNER, PLUG, FLY, SOFTPLASTIC};

// Declare product base class
class Lure {
    public:
        static std::unique_ptr<Lure> setLure(lureTypes type, const std::string& char1, const std::string& char2, const std::string& char3);
        virtual void getLure() = 0;
};

// Declare derived product classes
class FactoryJig : public Lure {
    public:
        FactoryJig(std::string characteristic1, std::string characteristic2, std::string characteristic3);
        void getLure();
    private:
        // Jig characteristics
        std::string weight, head_type, trailer_type;
};

class Spinner : public Lure {
    public:
        Spinner(std::string characteristic1, std::string characteristic2, std::string characteristic3);
        void getLure();
    private:
        // Spinner characteristics
        std::string weight, blade_type, blade_pattern;
};

class FactoryPlug : public Lure {
    public:
        FactoryPlug(std::string characteristic1, std::string characteristic2, std::string characteristic3);
        void getLure();
    private:
        // Plug characteristics
        std::string length, plug_type, color_pattern;
};

class FactoryFly : public Lure {
    public:
        FactoryFly(std::string characteristic1, std::string characteristic2, std::string characteristic3);
        void getLure();
    private:
        // Fly characteristics
        std::string length, tied_pattern, color_pattern;
};

class SoftPlastic : public Lure {
    public:
        SoftPlastic(std::string characteristic1, std::string characteristic2, std::string characteristic3);
        void getLure();
    private:
        // Soft plastic characteristics
        std::string length, style, color_pattern;
};
