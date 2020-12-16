#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <vector>

struct RollRequest {
    RollRequest() {
        _Sides = 6;
        _RollCount = DEFAULT_ROLLCOUNT;
    }
    RollRequest(int Sides) {
        _Sides = Sides;
        _RollCount = DEFAULT_ROLLCOUNT; // default
    }
    RollRequest(int Sides, int RollCount) {
        RollRequest(Sides);
        _RollCount = RollCount;
    }
    RollRequest(int Sides, int RollCount, int Modifier) {
        RollRequest(Sides, RollCount);
        _Modifier = Modifier;
    }

    int GetSides() {
        return _Sides;
    }
    int GetRollCount() {
        return _RollCount;
    }
    int GetModifier() {
        return _Modifier;
    }

private:
    int _Sides;
    int _RollCount;
    int _Modifier;

    const int DEFAULT_ROLLCOUNT = 1;
};

struct RollResult {
    RollResult(int Result, int Sides, int RollCount) {
        _Result = Result;
        _Sides = Sides;
        _RollCount = RollCount;
    }
    RollResult(int Result, int Sides, int RollCount, std::vector<int> Rolls) {
        RollResult(Result, Sides, RollCount);
        _Rolls = Rolls;
    }

    int GetResult() {
        return _Result;
    }
    int GetSides() {
        return _Sides;
    }
    int GetRollCount() {
        return _RollCount;
    }

private:
    int _Result;
    std::vector<int> _Rolls;
    int _Sides;
    int _RollCount;
};

std::vector<RollResult> Roll(const std::vector<RollRequest>&);

#endif