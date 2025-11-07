// shared.c

#include "shared.h"
#include <stdbool.h>
#include <string.h>

const int VALID_ART_YEARS[] = {2024, 2023, 2022, 2021, 2020};
const int VALID_ART_YEARS_COUNT = 5;

// This replaces the data in uue, e0, and the logic in aue
const AppConfig ALL_APP_CONFIGS[] = {
    {"graphing", "/assets/img/apps/graphing/favicon.ico", "/calculator"},
    {"geometry-calculator", "/assets/img/apps/geometry/favicon.ico", "/geometry"},
    {"graphing-3d", "/assets/img/apps/3d/favicon.ico", "/3d"},
    {"notebook", "/assets/img/apps/notebook/favicon.ico", "/notebook"}
};

// JavaScript function: function oue(t) { ... }
// Checks if the app is a known calculator type.
bool is_valid_calculator_app(const char* app_name) {
    if (!app_name) return false;
    for (int i = 0; i < APP_COUNT; i++) {
        if (strcmp(app_name, ALL_APP_CONFIGS[i].name) == 0) {
            // Check only for the core calculator types (excluding notebook)
            return (AppType)i != APP_NOTEBOOK;
        }
    }
    return false;
}

// JavaScript Validator (Np class) equivalent
// In C, you'd use a struct to hold validation rules
typedef struct {
    bool is_required;
    int min_value;
    int max_value;
    const char** enum_values;
    int enum_count;
} ValidationRules;

// A simple C function to check a number against range rules
bool validate_number_range(int value, const ValidationRules* rules) {
    if (rules->min_value != 0 && value < rules->min_value) return false;
    if (rules->max_value != 0 && value > rules->max_value) return false;
    return true;
}