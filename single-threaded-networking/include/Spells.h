#ifndef SPELLS_H
#define SPELLS_H

#include <unordered_map>

#include "SpellInterface.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"
#include "Player.h"
#include "Context.h"
namespace Spells{

	class DefenseSpell : public Spell
	{
	private:
		int duration;
		int mana;
		int minLevel;
		std::string name;
		std::vector<string> effect;
		std::vector<string> dammsg;
		std::vector<string> hitChar;
		std::vector<string> hitRoom;
		std::vector<string> hitVict;
		std::vector<string> wearOff;
		networking::Connection connection;

	public:
		//Constructor
		DefenseSpell()
		DefenseSpell(int duration_, int mana_, int minLevel, std::string& name_);
		
		std::string getName()const;
		//
		std::vector<string> getEffect()const;
		void setEffect(std::vector<string> effect_);

		//
		std::vector<string> getDammsg()const;
		void setDammsg(std::vector<string> dammsg_);

		//
		std::vector<string> getHitChar()const;
		void setHitChar(std::vector<string> hitChar);

		//
		std::vector<string> getHitRoom()const;
		void setHitRoom(std::vector<string> hitRoom);

		//
		std::vector<string> getHitVict()const;
		void setHitVict(std::vector<string> hitvict);

		//
		std::vector<string> getWearoff()const;
		void setWearoff(std::vector<string> wearoff);

		DefenseSpell(networking::Connection_,);
		std::string execute(Context& context);
		networking::Connection getConnection() const;



		
	};

	class OffenseSpell : public Spell {
	private:
		int duration;
		int Mana;
		int Minlevel;

		std::string Name;

		std::vector<string>  Dammsg;
		std::vector<string>  Missromm;
		std::vector<string>  Effect; 
		std::vector<string>  Hitchar;
		std::vector<string>  Hitroom;
		std::vector<string>  Hitvict;
		std::vector<string>  Immchar;
		std::vector<string>  Wearoff;

	public:
		//Constructor
		DefenseSpell()
		DefenseSpell(int duration_, int mana_, int minLevel, std::string& name_);
		
		std::string getName()const;
		//
		std::vector<string> getEffect()const;
		void setEffect(std::vector<string> effect);

		//
		std::vector<string> getDammsg()const;
		void setDammsg(std::vector<string> dammsg);

		//
		std::vector<string> getHitChar()const;
		void setHitChar(std::vector<string> hitChar);

		//
		std::vector<string> getHitRoom()const;
		void setHitRoom(std::vector<string> hitRoom);

		//
		std::vector<string> getHitVict()const;
		void setHitVict(std::vector<string> hitvict);

		//
		std::vector<string> getImmchar()const;
		void setImmchar(std::vector<string> immchar);

		//
		std::vector<string> getWearoff()const;
		void setWearoff(std::vector<string> wearoff);

		DefenseSpell(networking::Connection_,);
		std::string execute(Context& context);
		networking::Connection getConnection() const;

	};
}


#endif
