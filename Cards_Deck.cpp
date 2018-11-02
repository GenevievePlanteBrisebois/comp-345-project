//this class is made by Genevieve Plante-Brisebois 40003112 for COMP 345 in fall 2018

#include <iostream>
#include <cstdlib>
#include <string>
#include "Cards.h"
#include "Cards_Deck.h"

using namespace std;

Cards* regular_deck[64];
Cards* special_cards[2];

//making child class cards deck

	//getters for the deck
	Cards* Cards_Deck::getRegularCard(int i) {
		return regular_deck[i];
	}

	Cards* Cards_Deck::getSpecialCards(int i) {
		return special_cards[i];
	}


	//method to shuffle the cards of the deck
	void Cards_Deck::shuffle(Cards* regular_deck[]) {
		Cards* temp[64];
		bool shuffle = true;
		bool innerLoop = true;
		int k = 0;
		int i;
		bool occupied, complete;
		//make a temporary array that will store the suffled values
		while (shuffle = true) {
			i = rand() % 63;
			for (int j = 0; j < 64; j++) {
				if (temp[j] != nullptr) {
					occupied = true;
				}
				else
					occupied = false;
			}
			if (occupied == false) {
				temp[i] = regular_deck[k];
				k = k + 1;
			}

			//verify if the whole temp array has been filled

			for (int j = 0; j < 64; j++) {
				if (temp[j] == nullptr)
					complete = false;
			}
			if (complete != false) {
				complete = true;
				shuffle = false;
			}

		}
		//replace the order of the cards in the regular deck by the cards in the temp 
		for (int j = 0; j < 64; j++) {
			regular_deck[j] = temp[j];
		}

		delete[] * temp;

	}


	Cards* diva = new Cards("Diva", 5, "keep", "The other monsters need 4 Victory to take the Superstar from you");
	Cards* hunter = new Cards("Hunter", 5, "keep", "Heal 1 damage every time you destroy an Infantry");
	Cards* central_park = new Cards("Central Park", 5, "discard", "Buy this card for 1 energy point less if you are on the island of Manhattan. +2 Victory Points and heal 2 damage");
	Cards* curse = new Cards("Curse", 4, "keep", "When you deal damage to monsters, give each a curse token. Each time a monster wants to reroll OUCH he must spend 1 energy point for each curse token he has. A monster may use a heart to discard a curse token instead of using it to heal.");
	Cards* jinx_aura = new Cards("Jinx Aura", 4, "keep", "Other monsters must always use all their rerolls. (They sill get to choose which dice to reroll) ");
	Cards* towering_Titan = new Cards("Towering Titan", 10, "keep", "Add 2 ATTACK to your result.");
	Cards* painbow = new Cards("Painbow", 5, "keep", "If your results are:  2 DESTRUCTION, you get an extra ATTACK,  4 DESTRUCTION, you get an extra 2 ATTACK, 6 DESTRUCTION, you win the game!");
	Cards* unisphere = new Cards("The Unisphere", 5, "discard", "Buy this card for 1 ENERGY_POINT less if you are in QUEENS. +4 VICTORY_POINT.");
	Cards* sharp_shooter = new Cards("Sharp Shooter", 4, "keep", "You can destroy Jets that are not in your borough. Gain 1 VICTORY_POINT each time you destroy a Jet.");
	Cards* stomp = new Cards("Stomp", 4, "keep", "Add 1 destruction to your result");
	Cards* king_of_queens = new Cards("King od Queens", 5, "keep", "Gain 1 energy and heal 1 damage when you start your turn in Queens");
	Cards* power_substation = new Cards("Power Substation", 5, "discard", "+1 victory point, +8 energy points and take 3 damage");
	Cards* flatiron_building = new Cards("Flatiron Building", 3, "discard", "Buy this card for 1 ENERGY_POINT less if you are in MANHATTAN.+2 VICTORY_POINT.");
	Cards* super_speed = new Cards("Super Speed", 4, "keep", "you can have an extra move before rolling your dice");
	Cards* drain = new Cards("Drain", 4, "keep", "Take 2 energy point from monsters that attack you.");
	Cards* power_trap = new Cards("Power Trap", 4, "keep", "Each time a Monster gains at least 3 ENERGY_POINT in a turn, he must pay you 1 ENERGY_POINT.");
	Cards* bullet_proof = new Cards("Bullet Proof", 4, "keep", "Whenever you take a damage because of rolling ouch, you take 1 less damage");
	Cards* general_ellis = new Cards("General Ellis", 5, "discard", "You can only buy this card if you destroyed a Tank this turn.\n+3 VICTORY_POINT and all Monsters take 1 damage.");
	Cards* coney_island = new Cards("Coney Island", 4, "discard", "Buy this card for 1 ENERGY_POINT less if you are in BROOKLYN.+3 VICTORY_POINT.");
		Cards* personal_spotlight = new Cards("Personal Spotlight", 5, "keep", "Gain 1 victory point each turn you rolled at least 1 Victory");
		Cards* shadow_double = new Cards("Shadow Double", 12, "keep", "Whenever you attack you deal double damage");
		Cards* tesla_antennae = new Cards("Tesla Antennae", 4, "keep", "Monsters that have more HEART_POINT than you take 1 extra damage whenever you attack them.");
		Cards* leveler = new Cards("Leveler", 5, "keep", "gain 1 victory point each turn that you destroy at least one building");
		Cards* air_force_one = new Cards("Air FOrce One", 6, "discard", "You can only buy this card if you destroyed a Jet this turn.+4 VICTORY_POINT and all Units attack all Monsters in their boroughs.");
		Cards* drink_hudson = new Cards("Drink The Hudson", 12, "discard", "Buy this card for 1 ENERGY_POINT less if you are in MANHATTAN, BROOKLYN, or STATEN ISLAND.+13 ENERGY_POINT, +1 VICTORY_POINT, and heal 2 damage.");
		Cards* carapace = new Cards("Carapace", 3, "keep", "Your HEART_POINT maximum is increased by 2 as long as you have this card. For each OUCH you roll, place a Carapace token on this card.You can discard this card to heal 1 damage for each Carapace token on it.");
		Cards* fury = new Cards("Fury", 4, "keep", "Add 1 DESTRUCTION and 1 ENERGY_POINT to your roll if you are in a borough with at least 3 Units.");
		Cards* pheonix_blood = new Cards("Pheonix Blood", 4, "keep", "Gain 1 energy point each time you take damage");
		Cards* terminal_rage = new Cards("Terminal Rage", 4, "keep", "Take another turn when you buy this card.From now on you can no longer reroll ATTACK.");
		Cards* new_york_marathon = new Cards("New York Marathon", 6, "discard", "While this card is available for purchase, Monsters must pay 2 ENERGY_POINT to move (including fleeing from MANHATTAN), unless the movement is obligatory.+2 VICTORY_POINT, +2 ENERGY_POINT, and heal 2 damage.");
		Cards* photo_op = new Cards("Photo Op", 4, "discard", "Choose a Monster. Gain 1 VICTORY_POINT for each damage you dealt to that Monster this turn.");
		Cards* trash_thrower = new Cards("Trash Thrower", 5, "keep", "Monsters you attack lose 1 Victory Point");
		Cards* universal_soldier = new Cards("Universal Soldier", 6, "keep", "You can change some or all of your HEART to ATTACK, and/or your ATTACK to HEART.");
		Cards* can_opener = new Cards("Can Opener", 4, "keep", "You only need 3 destruction to destroy a Tank");
		Cards* ego_trip = new Cards("Ego Trip", 3, "keep", "Gain 1 ENERGY_POINT when you take Superstar and when you start your turn with it.");
		Cards* subway = new Cards("Subway", 10, "discard", "Heal 2 damage and take another turn.During this extra turn, you can move as often as you like, whenever you like.");
		Cards* hotland_tunnel = new Cards("Hotland Tunnel", 9, "discard", "Buy this card for 1 ENERGY_POINT less if you are in MANHATTAN.+6 VICTORY_POINT and all Monsters gain 3 ENERGY_POINT.");
		Cards* regeneration = new Cards("Regeneration", 5, "keep", "Heal 1 damage at the start of your turn");
		Cards* webspinner = new Cards("WebSpinner", 6, "keep", "When you deal damage to Monsters, give them a Web token. A Monster has one fewer reroll on his turn for each Web token he has.A Monster can choose to use an ATTACK to discard a Web token instead of using it to attack.");
		Cards* stink_attack = new Cards("Stink Attack", 5, "keep", "Whenever you move, you may disperse up to four Units from your destination borough. Each dispersed Unit must move to a separate borough.");
		Cards* of_another_world = new Cards("Of Another World", 6, "keep", "You can use HEART_POINT as ENERGY_POINT and ENERGY_POINT as HEART_POINT.");
		Cards* next_stage = new Cards("Next Stage", 4, "discard", "Lose all your VICTORY_POINT.Gain 1 ENERGY_POINT or heal 1 damage for each VICTORY_POINT you lost this way.");
		Cards* columbia_university = new Cards("Columbia University", 6, "discard", "Buy this card for 1 ENERGY_POINT less if you are in MANHATTAN.+2 VICTORY_POINT and take the next KEEP card revealed, for free.");
		Cards* natural_selection = new Cards("Natural Selection", 2, "keep", "Gain 4 ENERGY_POINT and heal 4 damage when you buy this card.You roll an extra die.If you end your turn with at least 1 VICTORY, you lose this card, and all your HEART_POINT.");
		Cards* antimatter_pellets = new Cards("Antimatter Pellets", 4, "keep", "Monsters you attack must roll a die.Those that roll OUCH take double damage.");
		Cards* tourist = new Cards("Tourist", 6, "keep", "Place a Souvenir token in your current borough, and in each borough you enter that does not already have a Souvenir token. Gain 1 VICTORY_POINT and 1 ENERGY_POINT each time you place a Souvenir token.");
		Cards* violent_star = new Cards("Violent Star", 3, "keep", "Deal 2 damage to the Monster from whom you take Superstar.Deal 1 damage to the Monster who takes Superstar from you.");
		Cards* subterranean_cable = new Cards("Subterranean Cable", 0, "discard", "+4 energy and 4 damage");
		Cards* brooklyn_bridge = new Cards("Brooklyn Bridge", 6, "discard", "Buy this card for 1 ENERGY_POINT less if you are in BROOKLYN.+4 VICTORY_POINT.");
		Cards* chameleon = new Cards("Chameleon", 4, "keep", "You can discard as many VICTORY as you wish.For each VICTORY discarded, you can change the face of one of the dice you haven't resolved.");
		Cards* scavenger = new Cards("Scavenger", 3, "keep", "You can buy KEEP cards from the discard by spending 1 ENERGY_POINT less than their cost.");
		Cards* trophy_hunter = new Cards("Trophy Hunter", 5, "keep", "Gain one victory point each time you destroy a unit");
		Cards* hailing_cars = new Cards("Hailing Cars", 5, "keep", "You may add 2 DESTRUCTION to your result. If you do you can destroy only Units.");
		Cards* tesla_cannon = new Cards("Tesla Cannon", 5, "discard", "+2 VICTORY_POINT.All Monsters (including you) must discard one KEEP card.");
		Cards* climb_epire_state = new Cards("Climg The Empire State Building", 3, "keep", "If you roll 1 of each dice type in MANHATTAN, gain 2 VICTORY_POINT and take another turn.");
		Cards* overload = new Cards("Overload", 0, "keep", "Gain 4 ENERGY_POINT when you buy this card.Gain 1 ENERGY_POINT less when you roll any amount of ENERGY.");
		Cards* chinatown_regular = new Cards("Chinatown Regular", 3, "keep", "Heal 2 damage when you enter Manhattan.");
		Cards* long_neck = new Cards("Long Neck", 3, "keep", "you only need 2 destruction to destroy a Jet");
		Cards* extra_head = new Cards("Extra Head", 7, "keep", "you get 1 extra die.");
		Cards* yankee = new Cards("Yankee Stadium", 9, "discard", "Buy this card for 1 ENERGY less if you are in the BRONX.+5 VICTORY_POINT and heal 5 damage.");
		Cards* artificial_heart = new Cards("Artificial Heart", 4, "keep", "You can change some or all of your heart to Energy");
		Cards* broadway_star = new Cards("Broadway Star", 5, "keep", "Gain 1 VICTORY_POINT when you take Superstar, and when you start your turn with it.");
		Cards* seismic_ray = new Cards("Seismic Ray", 4, "keep", "Spend 1 ENERGY_POINT to use your DESTRUCTION in any borough other than where you are.");
		Cards* fireball = new Cards("Fireball", 4, "keep", "Your attacks also deal damage to the other monsters in your borough");

		Cards*  statue_liberty = new Cards("Statue of Liberty", 0, "goal", "Take this card if you roll at least 3 ouch. Gain 3 Victory Point when you take this card. Lose 3 Victory Points when you lose this card");
		Cards* superstar = new Cards("Superstar", 0, "goal", "Take this card when you roll at least 3 Victory. Gain 1 Victory Point, +1 Victory point for every additional Victory that has been rolled. While in possession of the card, each victory rolled gives 1 Victory Point. ");

//constructors and destructors
Cards_Deck::Cards_Deck()
{
	//regular cards deck
	//Cards* regular_deck[64];
	
	regular_deck[0] = diva;
	
	regular_deck[1] = hunter;
	
	regular_deck[2] = central_park;
	
	regular_deck[3] = curse;
	regular_deck[4] = jinx_aura;
	regular_deck[5] = towering_Titan;
	regular_deck[6] = painbow;
	regular_deck[7] = unisphere;
	regular_deck[8] = sharp_shooter;
	regular_deck[9] = stomp;
	regular_deck[10] = king_of_queens;
	regular_deck[11] = power_substation;
	regular_deck[12] = flatiron_building;
	regular_deck[13] = super_speed;
	regular_deck[14] = drain;
	regular_deck[15] = power_trap;
	regular_deck[16] = bullet_proof;
	regular_deck[17] = general_ellis;
	regular_deck[18] = coney_island;
	regular_deck[19] = personal_spotlight;
	regular_deck[20] = shadow_double;
	regular_deck[21] = tesla_antennae;
	regular_deck[22] = leveler;
	regular_deck[23] = air_force_one;
	regular_deck[24] = drink_hudson;
	regular_deck[25] = carapace;
	regular_deck[26] = fury;
	regular_deck[27] = pheonix_blood;
	regular_deck[28] = terminal_rage;
	regular_deck[29] = new_york_marathon;
	regular_deck[30] = photo_op;
	regular_deck[31] = trash_thrower;
	regular_deck[32] = universal_soldier;
	regular_deck[33] = can_opener;
	regular_deck[34] = ego_trip;
	regular_deck[35] = subway;
	regular_deck[36] = hotland_tunnel;
	regular_deck[37] = regeneration;
	regular_deck[38] = webspinner;
	regular_deck[39] = stink_attack;
	regular_deck[40] = of_another_world;
	regular_deck[41] = next_stage;
	regular_deck[42] = columbia_university;
	regular_deck[43] = natural_selection;
	regular_deck[44] = antimatter_pellets;
	regular_deck[45] = tourist;
	regular_deck[46] = violent_star;
	regular_deck[47] = subterranean_cable;
	regular_deck[48] = brooklyn_bridge;
	regular_deck[49] = chameleon;
	regular_deck[50] = scavenger;
	regular_deck[51] = trophy_hunter;
	regular_deck[52] = hailing_cars;
	regular_deck[53] = tesla_cannon;
	regular_deck[54] = climb_epire_state;
	regular_deck[55] = overload;
	regular_deck[56] = chinatown_regular;
	regular_deck[57] = long_neck;
	regular_deck[58] = extra_head;
	regular_deck[59] = yankee;
	regular_deck[60] = artificial_heart;
	regular_deck[61] = broadway_star;
	regular_deck[62] = seismic_ray;
	regular_deck[63] = fireball;



	


	//special cards deck
	//Cards* special_cards[2];
	
	special_cards[0] = statue_liberty;
	special_cards[1] = superstar;

}



Cards_Deck::~Cards_Deck()
{
	delete[] * special_cards;
	delete[] * regular_deck;


}
