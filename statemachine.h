#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <string>
#include <map>

// Structure to hold the outcome of a state transition, including the next state and any output associated with the transition.
struct TransitionOutput {
    std::string nextState; // The state to transition to.
    std::string output; // The output to produce during the transition.
};


class StateMachine {
private:
    std::string currentState; // The current state of the state machine.
    // Table mapping current states and inputs to their corresponding next states and outputs.
    std::map<std::string, std::map<std::string, TransitionOutput>> transitionOutputTable;

public:
    StateMachine();
    void handleOutput(const std::string& output);
    void input(const std::string& symbol);
    std::string getCurrentState() const;
    void run(); // Keep the run method in the class if it manipulates class members directly.
    void setStateForTesting(const std::string& newState);
};

#endif // STATEMACHINE_H
