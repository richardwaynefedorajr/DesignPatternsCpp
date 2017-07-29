# include <string>
# include <iostream>

class LureCharacteristics {
    public:
        virtual std::string getCharacteristic() = 0;
};

class Color : public LureCharacteristics {
    public:
        Color(std::string in_color);
        std::string getCharacteristic();
    private:
        std::string m_color;
};

class Weight : public LureCharacteristics {
    public:
        Weight(std::string in_weight);
        std::string getCharacteristic();
    private:
        std::string m_weight;
};

class Length : public LureCharacteristics {
    public:
        Length(std::string in_length);
        std::string getCharacteristic();
    private:
        std::string m_length;
};

class Depth : public LureCharacteristics {
    public:
        Depth(std::string in_depth);
        std::string getCharacteristic();
    private:
        std::string m_depth;
};

class LureType {
    public:
        virtual std::string getLureType() = 0;
};

class Jig : public LureType {
    Color* m_color;
    Weight* m_weight;
    public:
        Jig(Color *in_color, Weight *in_weight) : m_color(in_color), m_weight(in_weight) { }
};

class SoftPlastic : public LureType {
    Color* m_color;
    Length* m_length;
    public:
        SoftPlastic(Color* in_color, Length* in_length) : m_color(in_color), m_length(in_length) { }
};

class Crankbait : public LureType {
    Color* m_color;
    Length* m_length;
    Depth* m_depth;
    public:
        Crankbait(Color* in_color, Length* in_length, Depth* in_depth) : m_color(in_color), m_length(in_length), m_depth(in_depth) { }
};

class Spinnerbait : public LureType {
    Color* m_color;
    Weight* m_weight;
    public:
        Spinnerbait(Color *in_color, Weight *in_weight) : m_color(in_color), m_weight(in_weight) { }
};


