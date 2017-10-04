//
//  ex04.cpp
//  piscine_cpp_d15
//
//  Created by Fabien Martinez on 21/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <string>
#include "ex04.hpp"

template<> Tester<std::string>::Tester() {}
template<> Tester<int>::Tester() {}
template<> Tester<float>::Tester() {}
template<> Tester<double>::Tester() {}
template<> Tester<std::string>::~Tester() {}
template<> Tester<int>::~Tester() {}
template<> Tester<float>::~Tester() {}
template<> Tester<double>::~Tester() {}

template<> bool Tester<int>::equal(const int& A, const int& B) {return A == B;}
template<> bool Tester<float>::equal(const float& A, const float& B) {return A == B;}
template<> bool Tester<double>::equal(const double& A, const double& B) {return A == B;}
template<> bool Tester<std::string>::equal(const std::string& A, const std::string& B) {return A.compare(B) == 0;}

template <> bool equal(int const& A, int const &B) {return A == B;}
template <> bool equal(float const& A, float const &B) {return A == B;}
template <> bool equal(double const& A, double const &B) {return A == B;}
template <> bool equal(std::string const& A, std::string const &B) {return (A.compare(B) == 0);}

