/*
 * LoggerNode.h
 *
 *  Created on: 10.08.2016
 *      Author: ian
 */

#ifndef SRC_LOGGERNODE_H_
#define SRC_LOGGERNODE_H_

#include "HomieNode.hpp"


class LoggerNode: public HomieNode {
public:
	LoggerNode();

	virtual void setup() override;
	//void loop(); // loop() not necessary

	  virtual bool handleInput(const String  &property, const HomieRange& range, const String &value) override;

	enum E_Loglevel {
		INVALID=-1, DEBUG=0, INFO, ERROR, CRITICAL
	};

	void log(const String function, const E_Loglevel level, const String text) const;
	void logf(const String function, const E_Loglevel level, const char *format, ...) const;

	bool loglevel(E_Loglevel l) const {
		return ((uint_fast8_t) l >= (uint_fast8_t) m_loglevel);
	}

	void setLoglevel(E_Loglevel l) {
		if (l >= DEBUG && l <= CRITICAL) m_loglevel = l;
	}

private:
	E_Loglevel m_loglevel;
	bool logSerial;
	static const String levelstring[4];

};

extern LoggerNode LN;

#endif /* SRC_LOGGERNODE_H_ */
