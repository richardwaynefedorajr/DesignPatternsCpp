# include "CoR.h"

BaseWorker::BaseWorker() { m_next_worker = 0; } 
void BaseWorker::setNext(BaseWorker *in_worker) { m_next_worker = in_worker; }
void BaseWorker::addWorker(BaseWorker *in_worker) {
    if (in_worker) { m_next_worker->addWorker(in_worker); }
    else { m_next_worker = in_worker; }
}

void BaseWorker::service(FastFood in_request) { m_next_worker->service(in_request); }

void Cashier::service(FastFood in_request) {
    if ( in_request == change ) { std::cout << "Cashier gives customer change" << std::endl; }
    else { BaseWorker::service(in_request); }
}

void Cook::service(FastFood in_request) {
    if ( in_request == burger ) { std::cout << "Cook gives customer burger" << std::endl; }
    else if ( in_request == fries ) { std::cout << "Cook gives customer fries" << std::endl; }
    else { BaseWorker::service(in_request); }
}

void Runner::service(FastFood in_request) {
    if ( in_request == drink ) { std::cout << "Runner brings customer drink" << std::endl; }
    else { BaseWorker::service(in_request); }
}
