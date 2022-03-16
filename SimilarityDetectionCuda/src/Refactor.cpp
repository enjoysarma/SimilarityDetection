/**
 * Refactor.cpp - C++11 implementation of Refactor.h
 * This class does all refactoring - compression and decompression of Tiles
 */

#include "Refactor.h"

/**
 * For now, just extract tokenId from Token class object
 * TODO compress 4 tokens into one 32bit integer
 */
uint32_t Refactor::compressToken(Token* token)
{
    return (uint32_t)token->getTokenId();
}

uint32_t Refactor::compressFourTokens(uint32_t token1, uint32_t token2, uint32_t token3, uint32_t token4)
{
    return (uint32_t)((token1 << 24) | (token2 << 16) | (token3 << 8) | token4);
}

/**
 * This will compress existing vector of Tokens by combining 4 tokens into one 32bit integer.
 */
thrust::host_vector<uint32_t> Refactor::compressTokenVector(std::vector<Token*> tokens)
{
    thrust::host_vector<uint32_t> compressedTokens;
/*
    unsigned int tokens_size = tokens.size();
    for (unsigned int i = 0; i < tokens_size;)
    {
        uint32_t token1 = 0,
                 token2 = 0,
                 token3 = 0,
                token4 = 0;

        token1 = tokens[i++]->getTokenId();
        if (i < tokens_size)
        {
            token2 = tokens[i++]->getTokenId();
            if (i < tokens_size)
            {
                 token3 = tokens[i++]->getTokenId();
                 if (i < tokens_size)
                     token4 = tokens[i++]->getTokenId();
            }
        }

        compressedTokens.push_back(Refactor::compressFourTokens(token1, token2, token3, token4));
    }
*/
    for (auto it = tokens.begin(); it != tokens.end(); ++it)
    {
        compressedTokens.push_back(Refactor::compressToken(*it));
    }

    return compressedTokens;
}

Tile Refactor::decompressTile(uint32_t compTile)
{
    return  Tile((compTile & MASK_TILE_FPI) >> TILE_FPI_SH,
                 (compTile & MASK_TILE_SPI) >> TILE_SPI_SH,
                 (compTile & MASK_TILE_LEN)
                );
}

std::list<Tile> Refactor::decompressTileVector(thrust::host_vector<uint32_t> compressedTiles)
{
    std::list<Tile> tiles;

    for (auto it = compressedTiles.begin(); it != compressedTiles.end(); ++it)
    {
        tiles.push_back(Refactor::decompressTile(*it));
    }

    return tiles;
}

std::list<Tile> Refactor::decompressTileVector(thrust::host_vector<uint32_t> compressedTiles,
											   uint32_t ctSize
											  )
{
    std::list<Tile> tiles;

    for (uint32_t i = 0; i < ctSize; i++)
    {
        tiles.push_back(Tile((compressedTiles[i] & MASK_TILE_FPI) >> TILE_FPI_SH,
							 (compressedTiles[i] & MASK_TILE_SPI) >> TILE_SPI_SH,
							 (compressedTiles[i] & MASK_TILE_LEN)
							)
					   );
    }

    return tiles;
}
