//Tile.h

#ifndef _TILE_H_
#define _TILE_H_

struct Tile {
	unsigned int fpi;
	unsigned int spi;
	unsigned int len;

	Tile(int fpi, int spi, int len) {
		this->fpi = fpi;
		this->spi = spi;
		this->len = len;
	}

	bool operator > (const Tile& a) const
	{
		return (len > a.len) || (len == a.len && fpi < a.fpi) || (len == a.len && spi < a.spi);
	}

	bool operator >= (const Tile& a) const
	{
		return (len > a.len) || (len == a.len && fpi < a.fpi) || (len == a.len && spi < a.spi) || (len == a.len);
	}

	bool operator < (const Tile& a) const
	{
		return (len < a.len) || (len == a.len && fpi > a.fpi) || (len == a.len && spi > a.spi);
	}

};

#endif
