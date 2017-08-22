# include <string>
# include <iostream>

class LureCharacteristic {
    public:
        virtual std::string getCharacteristic() = 0;
};

class Color : public LureCharacteristic {
    public:
        Color(std::string in_color);
        std::string getCharacteristic();
    private:
        std::string m_color;
};

class Weight : public LureCharacteristic {
    public:
        Weight(std::string in_weight);
        std::string getCharacteristic();
    private:
        std::string m_weight;
};

class Length : public LureCharacteristic {
    public:
        Length(std::string in_length);
        std::string getCharacteristic();
    private:
        std::string m_length;
};

class Depth : public LureCharacteristic {
    public:
        Depth(std::string in_depth);
        std::string getCharacteristic();
    private:
        std::string m_depth;
};

class LureType {
    public:
        virtual void getLure() = 0;
};

class LeadJig : public LureType {
    LureCharacteristic* m_color;
    LureCharacteristic* m_weight;
    public:
        LeadJig(LureCharacteristic *in_color, LureCharacteristic *in_weight) : m_color(in_color), m_weight(in_weight) { }
        void getLure();
};

class PlasticSoft : public LureType {
    LureCharacteristic* m_color;
    LureCharacteristic* m_length;
    public:
        PlasticSoft(LureCharacteristic* in_color, LureCharacteristic* in_length) : m_color(in_color), m_length(in_length) { }
        void getLure();
};

class Crankbait : public LureType {
    LureCharacteristic* m_color;
    LureCharacteristic* m_length;
    LureCharacteristic* m_depth;
    public:
        Crankbait(LureCharacteristic* in_color, LureCharacteristic* in_length, LureCharacteristic* in_depth) : m_color(in_color), m_length(in_length), m_depth(in_depth) { }
        void getLure();
};

class Spinnerbait : public LureType {
    LureCharacteristic* m_color;
    LureCharacteristic* m_weight;
    public:
        Spinnerbait(LureCharacteristic *in_color, LureCharacteristic *in_weight) : m_color(in_color), m_weight(in_weight) { }
        void getLure();
};
