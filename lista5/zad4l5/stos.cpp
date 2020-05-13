#include "stos.h"

Stos::Stos(Stos const &rhs)
        : _size(rhs._size) {
    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane, nullptr);
    Ogniwo *copy, *tmp;
    tmp = rhs._pSzczyt;
    copy = _pSzczyt;
    while (tmp->_p_nastepny != nullptr) {
        tmp = tmp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(tmp->_dane, _pSzczyt->_p_nastepny);

        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt->_p_nastepny = nullptr;
    _pSzczyt = copy;
}

Stos &Stos::operator=(Stos const &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete _pSzczyt;
    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane, nullptr);
    Ogniwo *copy, *tmp;
    tmp = rhs._pSzczyt;
    copy = _pSzczyt;
    while (tmp->_p_nastepny != nullptr) {
        tmp = tmp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(tmp->_dane, _pSzczyt->_p_nastepny);

        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt->_p_nastepny = nullptr;
    _pSzczyt = copy;

    return *this;
}

std::ostream &operator<<(std::ostream &L, const Stos &stos) {
    Ogniwo *szczyt = stos._pSzczyt;
    while (szczyt != nullptr) {
        L << szczyt->_dane << ", ";
        szczyt = szczyt->_p_nastepny;
    }
    return L;
}

void Stos::reverse() {
    Ogniwo *teraz = _pSzczyt;
    Ogniwo *przed = nullptr;
    Ogniwo *po = nullptr;

    while (teraz != nullptr) {
        po = teraz->_p_nastepny;
        teraz->_p_nastepny = przed;

        przed = teraz;
        teraz = po;
    }
    _pSzczyt = przed;
}

Stos::~Stos() {
    while (!this->empty()) {
        this->pop();
    }
}