# include <memory>
# include <iostream>

class TestPointer {
    public:
        TestPointer(std::unique_ptr<int> unique_value, std::shared_ptr<int> shared_value, int *value);
        std::unique_ptr<int> m_unique_int;
        std::shared_ptr<int> m_shared_int;
        int *m_int;
        void printPointers();
};
