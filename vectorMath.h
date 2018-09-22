#pragma once
#include "raylib.h"
#include "Box2D/Box2D.h"

Vector2 operator*(int i, Vector2 v);
Vector2 operator+(Vector2 va, Vector2 vb);
Vector2 operator+(float i, Vector2 v);
Vector2 operator*(Vector2 v, float i);
float dotProduct(Vector2 va, Vector2 vb);
Vector3 operator*(int i, Vector3 v);
Vector3 operator+(Vector3 va, Vector3 vb);
Vector3 operator+(float i, Vector3 v);
Vector3 operator*(Vector3 v, float i);
float dotProduct(Vector3 va, Vector3 vb);
float dist(Vector2 va, Vector2 vb);
Vector2 b2Vec2toVector2(b2Vec2 v);