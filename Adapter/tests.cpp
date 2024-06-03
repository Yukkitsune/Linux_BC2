#include <gtest/gtest.h>
#include "monster_and_pet.h"

TEST(SlimeTest, NameTest) {
    Slime slime;
    EXPECT_EQ(slime.Name(), "Slime");
}

TEST(SlimeTest, AttackAbilityTest) {
    Slime slime;
    EXPECT_EQ(slime.AttackAbility(), 6);
}

TEST(SlimeTest, DefenseAbilityTest) {
    Slime slime;
    EXPECT_EQ(slime.DefenseAbility(), 20);
}

TEST(GoblinTest, NameTest) {
    Goblin goblin;
    EXPECT_EQ(goblin.Name(), "Goblin");
}

TEST(GoblinTest, AttackAbilityTest) {
    Goblin goblin;
    EXPECT_EQ(goblin.AttackAbility(), 30);
}

TEST(GoblinTest, DefenseAbilityTest) {
    Goblin goblin;
    EXPECT_EQ(goblin.DefenseAbility(), 10);
}

TEST(DragonTest, NameTest) {
    Dragon dragon;
    EXPECT_EQ(dragon.Name(), "Dragon");
}

TEST(DragonTest, AttackAbilityTest) {
    Dragon dragon;
    EXPECT_EQ(dragon.AttackAbility(), 1000);
}

TEST(DragonTest, DefenseAbilityTest) {
    Dragon dragon;
    EXPECT_EQ(dragon.DefenseAbility(), 500);
}
