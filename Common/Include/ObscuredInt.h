//! \file		ObscuredInt.h
//! \brief
//! \detail
//! \author		sehyun

#pragma once

#include "Common.h"


namespace ObscuredTypes
{
	///////////////////////////////////////////////////////////
	/// \class	ObscuredInt
	/// \brief	암호화된 Integer.
	///////////////////////////////////////////////////////////
	class COMMON_API ObscuredInt
	{
	public:
		ObscuredInt(int Value);

	public:
		void			ApplyNewCryptoKey(void);
		void			RandomizeCryptoKey(void);

		int				GetEncrypted(void);
		void			SetEncrypted(int Encryped);

	public:
		static void		SetNewCryptoKey(int Key)			{ CryptoKey = Key; }
		static int		Encrypt(int Value)					{ return Encrypt(Value, 0); }
		static int		Encrypt(int Value, int Key);

		static int		Decrypt(int Value)					{ return Decrypt(Value, 0); }
		static int		Decrypt(int Value, int Key);

#pragma region Operators
	public:
		ObscuredInt		operator ++(void);
		ObscuredInt		operator --(void);

		bool			operator ==(ObscuredInt& Value);
		bool			operator ==(int Value);
		bool			operator !=(ObscuredInt& Value);
		bool			operator !=(int Value);

		int				operator =(ObscuredInt& Value);

		ObscuredInt		operator =(int Value);

		operator int() 										{ return InternalDecrypt(); }
		operator int() const								{ return Decrypt(HiddenValue); }

#pragma endregion

	private:
		int				InternalDecrypt(void);

	private:
		int				HiddenValue;
		int				CurrentCryptoKey;
		bool			Inited;

		static int		CryptoKey;
	};
}