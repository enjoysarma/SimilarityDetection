/**
 * Refactoring.h - contains all neccessary functions to convert and prepare existing data types and containers
 * to fit GPU needs
 */

#ifndef REFACTOR_H
#define REFACTOR_H

#include "Token.h"
#include "Tile.h"

#include <thrust/host_vector.h>

#include <cstdint>
#include <list>

/**
 * Masks for Token compression & decompression
 */
#define TOKEN_ID_SH     24
#define MASK_TOKEN_ID   0xFF000000
#define MASK_LINE_NO    0x00FFFFFF

/**
 * Masks for Tile compression & decompression
 */
#define MASK_TILE_FPI   0xFFE00000
#define TILE_FPI_SH     21
#define MASK_TILE_SPI   0x001FFC00
#define TILE_SPI_SH     10
#define MASK_TILE_LEN   0x000003FF


class Refactor
{
public:
    // Token compression not needed in this revision. Just simply extract tokenID from tokens and dismiss everything else.
    // TODO In later revision, try to compress 4 tokens into one 32bit integer.
    //      That should work size-vise because there aren't many tokens in the first place
    static uint32_t compressToken(Token* token);
    static uint32_t compressFourTokens(uint32_t token1, uint32_t token2, uint32_t token3, uint32_t token4);
    static thrust::host_vector<uint32_t> compressTokenVector(std::vector<Token*> tokens);

    static Tile decompressTile(uint32_t compressedTile);
    static std::list<Tile> decompressTileVector(thrust::host_vector<uint32_t> compressedTiles);

    struct longerCompressedTile
    {
        uint32_t tile1;
        uint32_t tile2;
        bool result;

        __host__ __device__ bool operator()(const uint32_t& left, const uint32_t& right) const
        {
            return (left & MASK_TILE_LEN) > (right & MASK_TILE_LEN);
        }
    };

    struct isNotZero
    {
         __host__ __device__ bool operator()(const uint32_t& x) const { return x != 0; }
    };
};

#endif //REFACTOR_H
