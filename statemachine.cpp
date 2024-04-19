#include "statemachine.h"
#include <iostream>


// Constructor initializes the state machine with the starting state and the state transition table.
StateMachine::StateMachine() : currentState("s1") {
    // Initial state set to "s1" and the transition table is populated here.
    // The table maps from current states and inputs to next states and outputs.
    // Initialize transitionOutputTable with combined nextState and output
        transitionOutputTable = {
                {"s1",    {
                                  {"1", {"[1]",   "n"}},
                                  {"2", {"[2]",   "n"}},
                                  {"+", {"[+]",   "n"}},
                                  {"x", {"[x]",   "n"}}
                          }},
                {"[1]",   {
                                  {"1", {"[1,1]", "n"}},
                                  {"2", {"[1,2]", "n"}},
                                  {"+", {"[1,+]", "n"}},
                                  {"x", {"[1,x]", "n"}}
                          }},
                {"[2]",   {
                                  {"1", {"[1,2]", "n"}},
                                  {"2", {"[2,2]", "n"}},
                                  {"+", {"[2,+]", "n"}},
                                  {"x", {"[2,x]", "n"}}
                          }},
                {"[+]",   {
                                  {"1", {"[1,+]", "n"}},
                                  {"2", {"[2,+]", "n"}},
                                  {"+", {"s1",    "j"}},
                                  {"x", {"s1",    "j"}}
                          }},
                {"[x]",   {
                                  {"1", {"[1,x]", "n"}},
                                  {"2", {"[2,x]", "n"}},
                                  {"+", {"s1",    "j"}},
                                  {"x", {"s1",    "j"}}
                          }},
                {"[1,1]", {
                                  {"1", {"s1",    "j"}},
                                  {"2", {"s1",    "j"}},
                                  {"+", {"s1",    "2"}},
                                  {"x", {"s1",    "1"}}
                          }},
                {"[1,2]", {
                                  {"1", {"s1",    "j"}},
                                  {"2", {"s1",    "j"}},
                                  {"+", {"s1",    "3"}},
                                  {"x", {"s1",    "2"}}
                          }},
                {"[1,+]", {
                                  {"1", {"s1",    "2"}},
                                  {"2", {"s1",    "3"}},
                                  {"+", {"s1",    "j"}},
                                  {"x", {"s1",    "j"}}
                          }},
                {"[1,x]", {
                                  {"1", {"s1",    "1"}},
                                  {"2", {"s1",    "2"}},
                                  {"+", {"s1",    "j"}},
                                  {"x", {"s1",    "j"}}
                          }},
                {"[2,2]", {
                                  {"1", {"s1",    "j"}},
                                  {"2", {"s1",    "j"}},
                                  {"+", {"s1",    "4"}},
                                  {"x", {"s1",    "4"}}
                          }},
                {"[2,+]", {
                                  {"1", {"s1",    "3"}},
                                  {"2", {"s1",    "4"}},
                                  {"+", {"s1",    "j"}},
                                  {"x", {"s1",    "j"}}
                          }},
                {"[2,x]", {
                                  {"1", {"s1",    "2"}},
                                  {"2", {"s1",    "4"}},
                                  {"+", {"s1",    "j"}},
                                  {"x", {"s1",    "j"}}
                          }}
        };
    }
/**
 * Handles the output for a given state transition.
 * @param output The output associated with a transition. Special values include "n" for no output and "j" for "junk".
 */
void StateMachine::handleOutput(const std::string &output) {
        if (output == "n") {
            // No output
        } else if (output == "j") {
            std::cout << "Output: junk" << std::endl;
        } else {
            std::cout << "Output: " << output << std::endl;
        }
    }
/**
 * Processes an input symbol, transitioning to the next state and producing any defined output.
 * @param symbol The input symbol to process.
 */
void StateMachine::input(const std::string &symbol) {
        if (transitionOutputTable[currentState].find(symbol) == transitionOutputTable[currentState].end()) {
            std::cout << "Invalid input. No transition defined for this symbol from the current state." << std::endl;
            return;
        }

        const auto &transitionOutput = transitionOutputTable[currentState][symbol];
        currentState = transitionOutput.nextState;

        // Use handleOutput to manage the output
        handleOutput(transitionOutput.output);

        std::cout << "Transitioned to state: " << currentState << std::endl;
    }
/**
 * Retrieves the current state of the state machine.
 * @return The current state.
 */
std::string StateMachine::getCurrentState()  const {
        return currentState;
    }

// Initiates an interactive session where the user can input symbols and see state transitions and outputs.
void StateMachine::run()  {
        std::string inputSymbol;
        std::cout << "Enter \"q\" to quit." << std::endl;
        std::cout << "Starting state: " << this->getCurrentState() << std::endl;
        while (true) {
            std::cout << "Enter input symbol (1, 2, +, x): ";
            std::cin >> inputSymbol;

            if (inputSymbol == "q") {
                break;
            }

            this->input(inputSymbol);
            std::cout << "Current State: " << this->getCurrentState() << std::endl;
        }
    }
/**
* Sets the state of the machine to a specified state. Intended for testing purposes.
* @param newState The state to set the machine to.
*/
void StateMachine::setStateForTesting(const std::string& newState) {
    currentState = newState;
}

