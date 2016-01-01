#pragma once

/* Components list */
enum ComponentId
{
	POSITION_COMPONENT,
	SPRITE_COMPONENT,
	CONTROLLED_COMPONENT,
	VIEWPORT_COMPONENT,

	// Keep at the end !!!
	_COMPONENT_COUNT_
};

/* Base component struct */
struct Component
{
	int entity;
};