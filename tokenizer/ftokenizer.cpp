//
// Created by theoi on 3/22/2026.
//

#include "ftokenize.h"
#include <iostream>

using namespace std;

FTokenizer::FTokenizer(const char* fname) {
    _pos = 0;
    _blockPos = 0;
    _more = true;

    _f.open(fname);
    if (!_f.is_open()) {
        cout << "FILE DID NOT OPEN" << endl;
        _more = false;
        return;
    }

    if (!get_new_block()) {
        _more = false;
    }
}

bool FTokenizer::get_new_block() {
    char buffer[MAX_BLOCK + 1];

    _f.read(buffer, MAX_BLOCK);
    int bytes_read = _f.gcount();

    if (bytes_read <= 0) {
        _more = false;
        return false;
    }

    buffer[bytes_read] = '\0';
    _stk.set_string(buffer);
    _blockPos = 0;
    return true;
}

Token FTokenizer::next_token() {
    Token t;
    *this >> t;
    return t;
}

bool FTokenizer::more() {
    return _more;
}

int FTokenizer::pos() {
    return _pos;
}

int FTokenizer::block_pos() {
    return _blockPos;
}

FTokenizer& operator>>(FTokenizer& f, Token& t) {
    if (!f._more) {
        t.set_contents("");
        t.set_type(TOKEN_END);
        return f;
    }

    while (f._more) {
        if (f._stk.more()) {
            f._stk >> t;

            f._blockPos += t.token_str().length();
            f._pos += t.token_str().length();

            return f;
        }
        else {
            if (!f.get_new_block()) {
                f._more = false;
                t.set_contents("");
                t.set_type(TOKEN_END);
                return f;
            }
        }
    }

    t.set_contents("");
    t.set_type(TOKEN_END);
    return f;
}