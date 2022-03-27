/*
    Base.cpp

    Investigation of virtual methods and overriding

    Methods and functions are inlined to focus on virtual 
    mechanism.
*/

#include <string_view>
#include <cassert>

class Base {
public:
    std::string_view m1()         const { return "Base::m1()"; }
    virtual std::string_view m2() const { return "Base::m2()"; }
};

class Derived : public Base {
public:
    std::string_view m1() const { return "Derived::m1()"; }
    std::string_view m2() const { return "Derived::m2()"; }
};

class DerivedDerived : public Derived {
public:
    std::string_view m1() const { return "DerivedDerived::m1()"; }
    std::string_view m2() const { return "DerivedDerived::m2()"; }
};

std::string_view m1BValue(Base b) {
    return b.m1();
}

std::string_view m2BValue(Base b) {
    return b.m2();
}

std::string_view m1BPtr(Base* pb) {
    return pb->m1();
}

std::string_view m2BPtr(Base* pb) {
    return pb->m2();
}

std::string_view m1BRef(Base& b) {
    return b.m1();
}

std::string_view m2BRef(Base& b) {
    return b.m2();
}

std::string_view m1DValue(Derived b) {
    return b.m1();
}

std::string_view m2DValue(Derived b) {
    return b.m2();
}

std::string_view m1DPtr(Derived* pd) {
    return pd->m1();
}

std::string_view m2DPtr(Derived* pd) {
    return pd->m2();
}

std::string_view m1DRef(Derived& d) {
    return d.m1();
}

std::string_view m2DRef(Derived& d) {
    return d.m2();
}

int main() {

    {
        Base b;

        assert(b.m1() == "");
        assert(m1BValue(b) == "");
        assert(b.m2() == "");
        assert(m2BValue(b) == "");

        Base* pb = &b;

        assert(pb->m1() == "");
        assert(m1BPtr(pb) == "");
        assert(pb->m2() == "");
        assert(m2BPtr(pb) == "");

        Base& rb = b;

        assert(rb.m1() == "");
        assert(m1BRef(rb) == "");
        assert(rb.m2() == "");
        assert(m2BRef(rb) == "");
    }

    {
        Derived d;

        assert(d.m1() == "");
        assert(m1BValue(d) == "");
        assert(m1DValue(d) == "");
        assert(d.m2() == "");
        assert(m2BValue(d) == "");
        assert(m2DValue(d) == "");

        Base* pb = &d;

        assert(pb->m1() == "");
        assert(m1BPtr(pb) == "");
        assert(pb->m2() == "");
        assert(m2BPtr(pb) == "");

        Base& rb = d;

        assert(rb.m1() == "");
        assert(m1BRef(rb) == "");
        assert(rb.m2() == "");
        assert(m2BRef(rb) == "");

        Derived* pd = &d;

        assert(pd->m1() == "");
        assert(m1BPtr(pd) == "");
        assert(m1DPtr(pd) == "");
        assert(pd->m2() == "");
        assert(m2BPtr(pd) == "");
        assert(m2DPtr(pd) == "");

        Derived& rd = d;

        assert(rd.m1() == "");
        assert(m1BRef(rd) == "");
        assert(m1DRef(rd) == "");
        assert(rd.m2() == "");
        assert(m2BRef(rd) == "");
        assert(m2DRef(rd) == "");
    }

    {
        DerivedDerived dd;

        assert(dd.m1() == "");
        assert(m1BValue(dd) == "");
        assert(m1DValue(dd) == "");
        assert(dd.m2() == "");
        assert(m2BValue(dd) == "");
        assert(m2DValue(dd) == "");

        Base* pb = &dd;

        assert(pb->m1() == "");
        assert(m1BPtr(pb) == "");
        assert(pb->m2() == "");
        assert(m2BPtr(pb) == "");

        Base& rb = dd;

        assert(rb.m1() == "");
        assert(m1BRef(rb) == "");
        assert(rb.m2() == "");
        assert(m2BRef(rb) == "");

        Derived* pd = &dd;

        assert(pd->m1() == "");
        assert(m1BPtr(pd) == "");
        assert(m1DPtr(pd) == "");
        assert(pd->m2() == "");
        assert(m2BPtr(pd) == "");
        assert(m2DPtr(pd) == "");

        Derived& rd = dd;

        assert(rd.m1() == "");
        assert(m1BRef(rd) == "");
        assert(m1DRef(rd) == "");
        assert(rd.m2() == "");
        assert(m2BRef(rd) == "");
        assert(m2DRef(rd) == "");

        DerivedDerived* pdd = &dd;

        assert(pdd->m1() == "");
        assert(m1BPtr(pdd) == "");
        assert(m1DPtr(pdd) == "");
        assert(pdd->m2() == "");
        assert(m2BPtr(pdd) == "");
        assert(m2DPtr(pdd) == "");

        DerivedDerived& rdd = dd;

        assert(rdd.m1() == "");
        assert(m1BRef(rdd) == "");
        assert(m1DRef(rdd) == "");
        assert(rdd.m2() == "");
        assert(m2BRef(rdd) == "");
        assert(m2DRef(rdd) == "");
    }

    return 0;
}