//
//  main.cpp
//  gomoku
//
//  Created by Fabien Martinez on 12/10/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <QApplication>
#include <QtCore/qtimer.h>
#include <QtWidgets>
#include <iostream>
#include <QtWidgets/qdialog.h>
#include <string.h>
#include "GameEngine.h"
#include "IntroState.h"
#include "CoreFirstRuleTests.h"
#include "CoreWinnerTests.h"
#include "CoreSecondRuleTests.h"
#include "CoreWinnerTests.h"
#include "SpeedTests.h"

static void _tests() {
    std::vector<UnitTests *>tests;

    tests.push_back(new CoreFirstRuleTests());
    tests.push_back(new CoreSecondRuleTests());
    tests.push_back(new CoreWinnerTests());
    tests.push_back(new SpeedTests());
    for(std::vector<UnitTests *>::iterator it = tests.begin(); it != tests.end(); ++it) {
        (*it)->runTests();
    }

    for(std::vector<UnitTests *>::iterator it = tests.begin(); it != tests.end(); ++it) {
        (*it)->testPassed();
        delete((*it));
    }
}

int main(int ac, char *av[]) {
    if (ac > 1 && !strcmp(av[1], "--tests")) {
        _tests();
    } else {
        // QT
        // ====================
        try {
            QApplication app(ac, av);

            app.setOrganizationName("Zero");
            app.setApplicationName("Gomoku");

            Arbiter *arbiter = new Arbiter();
            GameEngine *engine = new GameEngine(arbiter);
            IntroState *intro = new IntroState(engine, engine, arbiter);
            if (intro->exec() != QDialog::Accepted)
                return 1;

            engine->init();
            engine->show();

            return app.exec();
        } catch (ErrorGomoku const &e) {
            std::cerr << "Error in " << e.getComponent() << ": " << e.what() << std::endl;
        }
    }
    return 0;
}

