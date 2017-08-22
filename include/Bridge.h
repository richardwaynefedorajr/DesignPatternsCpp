# include <string>
# include <iostream>
# include <memory>

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
    std::shared_ptr<LureCharacteristic> m_color;
    std::shared_ptr<LureCharacteristic> m_weight;
    public:
        LeadJig(std::shared_ptr<LureCharacteristic> in_color, std::shared_ptr<LureCharacteristic> in_weight) : m_color(in_color), m_weight(in_weight) { }
        void getLure();
};

class PlasticSoft : public LureType {
    std::shared_ptr<LureCharacteristic> m_color;
    std::shared_ptr<LureCharacteristic> m_length;
    public:
        PlasticSoft(std::shared_ptr<LureCharacteristic> in_color, std::shared_ptr<LureCharacteristic> in_length) : m_color(in_color), m_length(in_length) { }
        void getLure();
};

class Crankbait : public LureType {
    std::shared_ptr<LureCharacteristic> m_color;
    std::shared_ptr<LureCharacteristic> m_length;
    std::shared_ptr<LureCharacteristic> m_depth;
    public:
        Crankbait(std::shared_ptr<LureCharacteristic> in_color, std::shared_ptr<LureCharacteristic> in_length, std::shared_ptr<LureCharacteristic> in_depth) : m_color(in_color), m_length(in_length), m_depth(in_depth) { }
        void getLure();
};

class Spinnerbait : public LureType {
    std::shared_ptr<LureCharacteristic> m_color;
    std::shared_ptr<LureCharacteristic> m_weight;
    public:
        Spinnerbait(std::shared_ptr<LureCharacteristic> in_color, std::shared_ptr<LureCharacteristic> in_weight) : m_color(in_color), m_weight(in_weight) { }
        void getLure();
};
