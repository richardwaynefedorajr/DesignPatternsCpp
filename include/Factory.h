# include <iostream>
# include <stdio.h>
# include <string>
# include <memory>

enum lureTypes {JIG, SPINNER, PLUG, FLY, SOFTPLASTIC};

// Declaration of a lure base class to create derived class instances
class Lure {
    public:
        static std::unique_ptr<Lure> setLure(lureTypes type, const std::string& char1, const std::string& char2, const std::string& char3);
        virtual void getLure() = 0;
};

// Declaration of derived lure classes of various types
class Jig : public Lure {
    public:
        Jig(std::string characteristic1, std::string characteristic2, std::string characteristic3);
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

class Plug : public Lure {
    public:
        Plug(std::string characteristic1, std::string characteristic2, std::string characteristic3);
        void getLure();
    private:
        // Plug characteristics
        std::string length, plug_type, color_pattern;
};

class Fly : public Lure {
    public:
        Fly(std::string characteristic1, std::string characteristic2, std::string characteristic3);
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
