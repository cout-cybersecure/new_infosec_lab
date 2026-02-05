package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"os"
	"os/exec"
)

type MRConfig struct {
	SourceBranch string   `json:"source_branch"`
	TargetBranch string   `json:"target_branch"`
	Title        string   `json:"title"`
	Author       string   `json:"author"`
	Reviewers    []string `json:"reviewers"`
}

func createMR(configPath string) {
	data, err := os.ReadFile(configPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading config: %v\n", err)
		os.Exit(1)
	}

	var config MRConfig
	if err := json.Unmarshal(data, &config); err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing config: %v\n", err)
		os.Exit(1)
	}

	cmd := exec.Command("./build/libinfosec_lab.so", "create-mr",
		config.SourceBranch, config.TargetBranch, config.Title, config.Author)
	output, err := cmd.Output()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
		os.Exit(1)
	}
	fmt.Print(string(output))
}

func main() {
	action := flag.String("action", "", "Action to perform")
	config := flag.String("config", "", "Config file path")
	flag.Parse()

	switch *action {
	case "create-mr":
		if *config == "" {
			fmt.Fprintf(os.Stderr, "Config file required\n")
			os.Exit(1)
		}
		createMR(*config)
	default:
		fmt.Fprintf(os.Stderr, "Unknown action: %s\n", *action)
		os.Exit(1)
	}
}
