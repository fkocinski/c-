#include "stos.h"

Stos::Stos(Stos const &rhs)
        : _size(rhs._size) {
    if (rhs.empty()) {
        _pSzczyt = new Ogniwo(0, nullptr);
    } else {
        _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane, 0);
    }
    Ogniwo *copy, *tmp;
    tmp = rhs._pSzczyt;
    copy = _pSzczyt;
    while (copy->_p_nastepny != NULL) {
        tmp = tmp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(tmp->_dane, _pSzczyt->_p_nastepny);

        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt->_p_nastepny = NULL;
    _pSzczyt = copy;
}

Stos &Stos::operator=(Stos const &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete _pSzczyt;
    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane, 0);
    Ogniwo *copy, *tmp;
    tmp = rhs._pSzczyt;
    copy = _pSzczyt;
    while (tmp->_p_nastepny != NULL) {
        tmp = tmp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(tmp->_dane, _pSzczyt->_p_nastepny);

        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt->_p_nastepny = NULL;
    _pSzczyt = copy;

    return *this;
}


Stos::~Stos() {
    while (!this->empty()) {
        this->pop();
    }
}