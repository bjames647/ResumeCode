using UnityEngine;
using System.Collections;

public class collision : MonoBehaviour {

	public void OnCollisionEnter(Collision col){
		if (col.gameObject.tag == "wall") {
			Destroy (col.gameObject);
		}
	}
}
