# include "PointerVariations.h"

TestPointer::TestPointer(std::unique_ptr<int> unique_value, std::shared_ptr<int> shared_value, int *value) {
    m_unique_int = std::move(unique_value);
    m_shared_int = shared_value;
    m_int = value;
}

void TestPointer::printPointers() {
    std::cout << "Unique pointer location: " << m_unique_int.get() << " value: " << *m_unique_int << std::endl;
    std::cout << "Shared pointer location: " << m_shared_int.get() << " value: " << *m_shared_int << std::endl;
    std::cout << "Raw pointer location: " << m_int << " value: " << *m_int << std::endl;
}
