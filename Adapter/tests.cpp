#include "monster_and_pet.h"
#include <gtest/gtest.h>

TEST(MonsterTest, SlimeAttributes) {
    Slime slime;
    EXPECT_EQ(slime.Name(), "Slimesgasdfgg");
    EXPECT_EQ(slime.AttackAbility(), 6423);
    EXPECT_EQ(slime.DefenseAbility(), 2034);
}

TEST(MonsterTest, GoblinAttributes) {
    Goblin goblin;
    EXPECT_EQ(goblin.Name(), "Goblin");
    EXPECT_EQ(goblin.AttackAbility(), 30);
    EXPECT_EQ(goblin.DefenseAbility(), 10);
}

TEST(MonsterTest, DragonAttributes) {
    Dragon dragon;
    EXPECT_EQ(dragon.Name(), "Dragon");
    EXPECT_EQ(dragon.AttackAbility(), 1000);
    EXPECT_EQ(dragon.DefenseAbility(), 500);
}

TEST(PetAdapterStaticTest, SlimeAsPet) {
    PetAdapterStatic<Slime> petSlime;
    EXPECT_EQ(petSlime.Name(), "Slime");
    EXPECT_EQ(petSlime.CutenessAbility(), 20 - 2 * 6); // 20 - 12 = 8
    EXPECT_EQ(petSlime.BattleBonus(), 6 + 20 / 2); // 6 + 10 = 16
}

TEST(PetAdapterDynamicTest, ChangeMonster) {
    auto slime = std::make_unique<Slime>();
    auto goblin = std::make_unique<Goblin>();
    PetAdapterDynamic petAdapter(std::move(slime));
    EXPECT_EQ(petAdapter.Name(), "Slime");

    petAdapter.ChangeMonster(std::move(goblin));
    EXPECT_EQ(petAdapter.Name(), "Goblin");
}
