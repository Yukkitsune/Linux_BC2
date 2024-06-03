#ifndef MONSTER_AND_PET_H
#define MONSTER_AND_PET_H

#include <iostream>
#include <memory>
#include <string>
#include <type_traits>

/* 태초에 Monster들이 존재했다.. */
class Monster
{
public:
    virtual ~Monster() = default;
    virtual std::string Name() const = 0;
    virtual int AttackAbility() const = 0;
    virtual int DefenseAbility() const = 0;
};

class Slime : public Monster
{
public:
    std::string Name() const override;
    int AttackAbility() const override;
    int DefenseAbility() const override;
};

class Goblin : public Monster
{
public:
    std::string Name() const override;
    int AttackAbility() const override;
    int DefenseAbility() const override;
};

class Dragon : public Monster
{
public:
    std::string Name() const override;
    int AttackAbility() const override;
    int DefenseAbility() const override;
};

/* 그리고 태초에 Pet들이 존재했다.. */
class Pet
{
public:
    virtual ~Pet() = default;
    virtual std::string Name() const = 0;
    virtual int CutenessAbility() const = 0;
    virtual int BattleBonus() const = 0;
};

class Puppy : public Pet
{
public:
    std::string Name() const override;
    int CutenessAbility() const override;
    int BattleBonus() const override;
};

class Cat : public Pet
{
public:
    std::string Name() const override;
    int CutenessAbility() const override;
    int BattleBonus() const override;
};

/* Monster를 정적으로(compile-time) Pet의 일부로서 만들고 싶은 경우 */
template <typename MonsterType, typename = std::enable_if_t<std::is_base_of<Monster, MonsterType>::value>>
class PetAdapterStatic : public Pet
{
public:
    std::string Name() const override;
    int CutenessAbility() const override;
    int BattleBonus() const override;

private:
    MonsterType monster_;
};

/* Monster를 동적으로(run-time) Pet의 일부로서 만들고 싶은 경우 */
class PetAdapterDynamic : public Pet
{
public:
    explicit PetAdapterDynamic(std::unique_ptr<Monster>&& monster);
    std::unique_ptr<Monster> ChangeMonster(std::unique_ptr<Monster>&& monster);

    std::string Name() const override;
    int CutenessAbility() const override;
    int BattleBonus() const override;

private:
    std::unique_ptr<Monster> monster_;
};

void PrintMonster(Monster const& monster);
void PrintPet(Pet const& pet);

#endif // MONSTER_AND_PET_H
