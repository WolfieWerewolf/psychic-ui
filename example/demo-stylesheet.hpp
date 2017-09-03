#pragma once

#include <psychicui/style/StyleManager.hpp>
#include <psychicui/style/StyleSheet.hpp>

using namespace psychicui;

/**
 * Demo Style
 * This style is loaded on top of the default PsychicUI stylesheet
 */
class DemoStyleSheet : public StyleSheet {
public:
    void load(StyleManager *manager) override {

        manager->style(".demo-panel")
               ->set(margin, 24)
               ->set(direction, "row");

        manager->style("buttons button")
               ->set(margin, 24)
               // Override the default in order to see the test result
               ->set(borderRadius, 0)
               ->set(borderColor, BASE_03);

    }
};