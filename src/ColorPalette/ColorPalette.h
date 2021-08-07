#pragma once

// From https://iquilezles.org/www/articles/palettes/palettes.htm
struct ColorPalette {
    glm::vec3 eval(float t)
    {
        return a + b * glm::cos(glm::two_pi<float>() * (c * t + d));
    }

    glm::vec3 a = {0.5f, 0.5f, 0.5f};
    glm::vec3 b = {0.5f, 0.5f, 0.5f};
    glm::vec3 c = {1.0f, 1.0f, 1.0f};
    glm::vec3 d = {0.0f, .33f, .67f};

private:
    // Serialization
    friend class cereal::access;
    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(
            cereal::make_nvp("a", a),
            cereal::make_nvp("b", b),
            cereal::make_nvp("c", c),
            cereal::make_nvp("d", d));
    }
};