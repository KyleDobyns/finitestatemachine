#include "statemachine.h"
#include <iostream>
#include <cassert>
#include <vector>

/**
 * Tests the state transitions of the StateMachine. This function is designed to validate
 * that the StateMachine correctly transitions between states and produces the expected output
 * for a series of predefined test cases. Each test case specifies an initial state, an input
 * symbol, the expected resulting state, and the expected output. The state machine is then
 * set to the initial state for each test case, processes the input symbol, and checks if
 * the resulting state matches the expected state.
 *
 * @param machine A reference to the StateMachine instance to be tested. This function
 *                directly manipulates the state of this instance to perform tests.
 */
    static void testTransitions(StateMachine& machine) {
        struct TestCase {
            std::string initialState;
            std::string input;
            std::string expectedState;
            std::string expectedOutput;
        };

        std::vector<TestCase> testCases = {
                {"s1", "1", "[1]", "n"},
                {"s1", "2", "[2]", "n"},
                {"s1", "+", "[+]", "n"},
                {"s1", "x", "[x]", "n"},
                {"[1]", "1", "[1,1]", "n"},
                {"[1]", "2", "[1,2]", "n"},
                {"[1]", "+", "[1,+]", "n"},
                {"[1]", "x", "[1,x]", "n"},
                {"[2]", "1", "[1,2]", "n"},
                {"[2]", "2", "[2,2]", "n"},
                {"[2]", "+", "[2,+]", "n"},
                {"[2]", "x", "[2,x]", "n"},
                {"[+]", "1", "[1,+]", "n"},
                {"[+]", "2", "[2,+]", "n"},
                {"[+]", "+", "s1", "j"},
                {"[+]", "x", "s1", "j"},
                {"[x]", "1", "[1,x]", "n"},
                {"[x]", "2", "[2,x]", "n"},
                {"[x]", "+", "s1", "j"},
                {"[x]", "x", "s1", "j"},
                {"[1,1]", "1", "s1", "j"},
                {"[1,1]", "2", "s1", "j"},
                {"[1,1]", "+", "s1", "2"},
                {"[1,1]", "x", "s1", "1"},
                {"[1,2]", "1", "s1", "j"},
                {"[1,2]", "2", "s1", "j"},
                {"[1,2]", "+", "s1", "3"},
                {"[1,2]", "x", "s1", "2"},
                {"[1,+]", "1", "s1", "2"},
                {"[1,+]", "2", "s1", "3"},
                {"[1,+]", "+", "s1", "j"},
                {"[1,+]", "x", "s1", "j"},
                {"[1,x]", "1", "s1", "1"},
                {"[1,x]", "2", "s1", "2"},
                {"[1,x]", "+", "s1", "j"},
                {"[1,x]", "x", "s1", "j"},
                {"[2,2]", "1", "s1", "j"},
                {"[2,2]", "2", "s1", "j"},
                {"[2,2]", "+", "s1", "4"},
                {"[2,2]", "x", "s1", "4"},
                {"[2,+]", "1", "s1", "3"},
                {"[2,+]", "2", "s1", "4"},
                {"[2,+]", "+", "s1", "j"},
                {"[2,+]", "x", "s1", "j"},
                {"[2,x]", "1", "s1", "2"},
                {"[2,x]", "2", "s1", "4"},
                {"[2,x]", "+", "s1", "j"},
                {"[2,x]", "x", "s1", "j"}
        };

        for (const auto& test : testCases) {
            machine.setStateForTesting(test.initialState); // Set the initial state
            machine.input(test.input);
            assert(machine.getCurrentState() == test.expectedState && "State transition test failed.");
        }

        std::cout << "All transition and output tests passed successfully." << std::endl;
    }

int main() {
    StateMachine machine;
    //Interactive menu.
//    machine.run();

  //Uncomment to run test cases.
  testTransitions(machine);

    return 0;
}
