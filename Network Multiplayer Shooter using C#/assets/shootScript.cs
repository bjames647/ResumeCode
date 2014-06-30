using UnityEngine;
using System.Collections;

public class shootScript : Photon.MonoBehaviour {
	public bool enableFire = false;
	public float bulletForce = 2000F;
	public Transform target;


	// Update is called once per frame
	void Update () {
		if (enableFire == true & Input.GetKeyDown("x")) {
			GameObject muzzle = GameObject.FindWithTag("character");
			GameObject myBullet = PhotonNetwork.Instantiate ("bullet", muzzle.transform.position, Quaternion.identity , 0);
			myBullet.rigidbody.AddRelativeForce(transform.forward * Time.deltaTime * 25000); 
						
		}
	
	}

	public void OnCollisionEnter(){

	//	if (col.gameObject.tag == "playerHit") { 
	//					playerHealth = playerHealth - 25;
	//		Debug.Log (playerHealth);		
	//	}
		PhotonNetwork.Destroy(gameObject);
		Destroy (gameObject);

	}


}
