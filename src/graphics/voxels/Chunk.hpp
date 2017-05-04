#ifndef VOXELSENGINE_CHUNK_HPP
#define VOXELSENGINE_CHUNK_HPP

#include <array>
#include <glm/vec3.hpp>
#include <graphics/opengl/Mesh.hpp>
#include <graphics/opengl/VertexArray.hpp>
#include <graphics/opengl/ArrayBuffer.hpp>
#include <graphics/opengl/IndexBuffer.hpp>
#include "Voxel.hpp"

using VoxelPtr = std::shared_ptr<Voxel>;

struct Chunk
{
    auto static constexpr chunkWidth = 64;
    auto static constexpr chunkHeight = 64;
    auto static constexpr chunkDepth = 64;
    auto static constexpr chunkSize = chunkWidth * chunkHeight * chunkDepth;

    bool needMeshing = true;

    Chunk(int id, glm::vec3 offset);
    const glm::vec3 getOffset() const;
    void meshing();
    void bind();
    void unbind();
    void draw();

private:

    int chunkId_;
    glm::vec3 offset_;
    std::array<VoxelPtr, chunkSize> voxels_ {};

    Mesh chunkMesh_;
    VertexArray vertexArray_;
    ArrayBuffer positionsBuffer_;
    ArrayBuffer colorsBuffer_;
    ArrayBuffer normalsBuffer_;
    IndexBuffer indicesBuffer_;
};


#endif //VOXELSENGINE_CHUNK_HPP
