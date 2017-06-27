# include <iostream>
# include <stdio.h>

enum lureTypes {JIG, SPINNER, PLUG, FLY, SOFTPLASTIC};

// Declaration of a factory class to create fishing lure objects
class Lure {
    public:
        static Lure *setLure(lureTypes type);
        virtual void getLure() = 0;
};

// Declaration of lure child classes
class Jig : public Lure {
    void getLure();
};

class Spinner : public Lure {
    void getLure();
};

class Plug : public Lure {
    void getLure();
};

class Fly : public Lure {
    void getLure();
};

class SoftPlastic : public Lure {
    void getLure();
};

