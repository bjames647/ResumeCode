using UnityEngine;
using System.Collections;

public class NetworkManager : Photon.MonoBehaviour {
	public bool respawn = false;
	public int playerHealth = 100;

	// Use this for initialization
	void Start () {
		PhotonNetwork.ConnectUsingSettings ("Alpha 0.01");
	}
	void OnGUI() {
		GUILayout.Label (PhotonNetwork.connectionStateDetailed.ToString ());
		GUILayout.Label (playerHealth.ToString ());
	}

	void OnJoinedLobby(){
		PhotonNetwork.JoinRandomRoom ();
	}

	void OnPhotonRandomJoinFailed() {
		PhotonNetwork.CreateRoom (null);
	}

	void OnJoinedRoom(){
		spawnPlayer ();
	}

	void spawnPlayer(){
		GameObject myPlayer = PhotonNetwork.Instantiate ("character", Vector3.one , Quaternion.identity, 0);
		myPlayer.GetComponent<CharacterControls> ().enableControls = true;
		myPlayer.GetComponent<shootScript> ().enableFire = true;
		myPlayer.GetComponent<shootScript> ().target = myPlayer.transform;
		Camera.main.GetComponent<CameraScript> ().target = myPlayer.transform;
	}

	public IEnumerator death(){
		if(PhotonNetwork.isMasterClient){

				if (playerHealth == 0) {
					PhotonNetwork.Destroy(this.gameObject);	
					respawn = true;
					yield return new WaitForSeconds(3);
					respawnPlayer();
					
				}
		}
	
	}
	public void respawnPlayer(){
		if (respawn == true) {
			spawnPlayer();		
		}
	}
	public void OnCollisionEnter(Collision col){
		
		if (col.gameObject.tag == "bullet") { 
			playerHealth = playerHealth - 10;		
		}

		
	}

}
