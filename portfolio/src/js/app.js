window.addEventListener("hashchange", (event) => {
	switch (window.location.hash) {
		case "#index":
			window.location = "./index.html";
			break;
		case "#gol":
			window.location = "./game_of_life.html";
			break;
		case "#empty":
			console.log("Empty selected");
			break;
		default:
			console.log("Page Not Found");
	}
});
