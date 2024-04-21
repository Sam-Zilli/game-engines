/**
 * @file ComponentType.hpp
 * @brief This file contains the definition of the ComponentType enum class.
 */

#pragma once

/**
 * @enum ComponentType
 * @brief An enum class that represents the type of a component.
 * @details This enum class is used as a key when adding a component to a game object.
 */
enum class ComponentType : short {
    TextureComponent,      ///< Represents a texture component.
    TransformComponent,    ///< Represents a transform component.
    Collision2DComponent,  ///< Represents a 2D collision component.
    InputComponent         ///< Represents an input component.
};