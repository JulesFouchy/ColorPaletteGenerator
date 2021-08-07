#pragma once

static std::string vec_to_string(glm::vec3 v)
{
    return fmt::format("{}{:f}f, {:f}f, {:f}f{}", "{", v.x, v.y, v.z, "}");
}

// From https://iquilezles.org/www/articles/palettes/palettes.htm
struct ColorPalette {
    std::string to_string()
    {
        return fmt::format("{}\n{},\n{},\n{},\n{}\n{}", "{", vec_to_string(a), vec_to_string(b), vec_to_string(c), vec_to_string(d), "};");
    }

    glm::vec3 a = {0.5f, 0.5f, 0.5f};
    glm::vec3 b = {0.5f, 0.5f, 0.5f};
    glm::vec3 c = {1.0f, 1.0f, 1.0f};
    glm::vec3 d = {0.0f, .33f, .67f};

private:
    // Serialization
    friend class cereal::access;
    template<class Archive>
    void save(Archive& archive) const
    {
        archive(
            cereal::make_nvp("a", a),
            cereal::make_nvp("b", b),
            cereal::make_nvp("c", c),
            cereal::make_nvp("d", d));
    }
    template<class Archive>
    void load(Archive& archive)
    {
        archive(
            cereal::make_nvp("a", a),
            cereal::make_nvp("b", b),
            cereal::make_nvp("c", c),
            cereal::make_nvp("d", d));
    }
};