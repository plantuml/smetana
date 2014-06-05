package smetana;

import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Signer {

	private final MessageDigest msgDigest;

	public Signer() {
		try {
			msgDigest = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			throw new UnsupportedOperationException(e);
		}
	}

	public void addLine(String s) {
		try {
			msgDigest.update(s.getBytes("UTF-8"));
		} catch (UnsupportedEncodingException e) {
			throw new UnsupportedOperationException(e);
		}
	}

	public String getSignature() {
		final byte[] digest = msgDigest.digest();
		final BigInteger bigInt = new BigInteger(1, digest);
		return bigInt.toString(36);
	}

}
