#include "CItemManager.h"

CItemManager * CItemManager::_singleton;

CItemManager * CItemManager::initialize()
{
	if (!_singleton)
		_singleton = new CItemManager();

	return _singleton;
}

CItemManager::CItemManager()
{
	_arrows[0] = 0;
	_arrows[1] = 0;
	_arrows[2] = 0;

	_bombs[0] = 0;
	_bombs[1] = 0;
	_bombs[2] = 0;

	_boomerang = 0;
}

CItemManager::~CItemManager()
{
	for (int i = 0; i < 3; i++)
	{
		if (_arrows[i])
			delete _arrows[i];

		if (_bombs[i])
			delete _bombs[i];
	}
}

void CItemManager::updateItems()
{
}