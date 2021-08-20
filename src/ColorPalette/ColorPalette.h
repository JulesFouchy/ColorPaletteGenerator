#pragma once

#include <Cool/String/String.h>

static std::string to_int_string(float x)
{
    int i = static_cast<int>(255.f * x);
    return (i < 10 ? "  " : i < 100 ? " " : "") + std::to_string(i);
}

// From https://iquilezles.org/www/articles/palettes/palettes.htm
struct ColorPalette {
    std::string to_string()
    {
        std::string s;
        for (int i = 0; i < 3; ++i) {
            bool no_inversion = min_val[i] <= max_val[i];
            s += "    {" +
                 to_int_string(no_inversion ? min_val[i] : max_val[i]) + ", " +
                 to_int_string(no_inversion ? max_val[i] : min_val[i]) + ", " +
                 to_int_string(frequency[i] * 60.f / 255.f) + ", " +
                 to_int_string(no_inversion ? phase[i] : 1.f - phase[i]) + "}, // " + (i == 0 ? "RED\n" : i == 1 ? "GREEN\n" : "BLUE");
        }
        return s;
    }

    glm::vec3 min_val   = {0.f, 0.f, 0.f};
    glm::vec3 max_val   = {1.f, 1.f, 1.f};
    glm::vec3 frequency = {1.0f, 1.0f, 1.0f};
    glm::vec3 phase     = {0.0f, .33f, .67f};

private:
    // Serialization
    friend class cereal::access;
    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(
            cereal::make_nvp("min_val", min_val),
            cereal::make_nvp("max_val", max_val),
            cereal::make_nvp("frequency", frequency),
            cereal::make_nvp("phase", phase));
    }
};