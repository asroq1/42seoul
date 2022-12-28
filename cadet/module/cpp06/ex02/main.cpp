/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:08:15 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/27 17:07:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

// void leaks() { system("leaks a.out"); }

Base *generate(void) {
    Base *obj = NULL;
    srand((unsigned int)time(NULL));
    int percent = rand() % 3;

    if (percent == 0) {
        return obj = new A();
    } else if (percent == 1) {
        return obj = new B();
    } else if (percent == 2) {
        return obj = new C();
    }
    return obj;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "This Call is A by Pointer" << std::endl;
    }
    if (dynamic_cast<B *>(p)) {
        std::cout << "This Call is B by Pointer" << std::endl;
    }
    if (dynamic_cast<C *>(p)) {
        std::cout << "This Call is C by Pointer" << std::endl;
    }
}

void identify(Base &p) {

    try {
        A &obj = dynamic_cast<A &>(p);
        (void)obj;
        std::cout << "This Call is A by Ref" << std::endl;
    } catch (const std::exception &e) {
    }
    try {
        B &obj = dynamic_cast<B &>(p);
        (void)obj;
        std::cout << "This Call is B by Ref" << std::endl;
    } catch (const std::exception &e) {
    }
    try {
        C &obj = dynamic_cast<C &>(p);
        (void)obj;
        std::cout << "This Call is C by Ref" << std::endl;
    } catch (const std::exception &e) {
    }
}

int main() {
    // atexit(leaks);
    Base *obj;

    obj = generate();
    std::cout << std::endl;

    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
