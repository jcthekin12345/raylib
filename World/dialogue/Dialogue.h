//
// Created by jctheking753 on 2024/12/02.
//

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

// First, let's create a structure for our dialogue data
struct DialogueNode {
    std::string speaker{};           // Who is speaking
    std::string text{};             // What they're saying
    std::string emotion{};          // Their emotional state
    std::vector<int> nextNodes{};   // Possible next dialogue options
};

// Helper class to manage dialogue and demonstrate searching
class DialogueManager {
private:
    std::vector<DialogueNode> dialogueNodes{};
    std::unordered_map<std::string, std::vector<std::size_t>> speakerIndex{};  // Index for quick speaker lookup

public:
    // Add a new dialogue node
    void addDialogue(const std::string& speaker, const std::string& text,
                    const std::string& emotion) {
        const DialogueNode node{speaker, text, emotion};
        dialogueNodes.push_back(node);

        // Update our speaker index
        speakerIndex[speaker].push_back(dialogueNodes.size() - 1);
    }

    // Demonstrate different search methods

    // 1. Linear search - O(n) complexity
    DialogueNode* findDialogueLinear(const std::string& searchText) {
        for (auto& node : dialogueNodes) {
            if (node.text.find(searchText) != std::string::npos) {
                return &node;
            }
        }
        return nullptr;
    }

    // 2. Binary search (if dialogueNodes is sorted) - O(log n) complexity
    // Note: This requires the vector to be sorted by some criteria
    long long findDialogueBinary(const std::string& targetSpeaker) {
        // First, ensure the vector is sorted by speaker
        std::sort(dialogueNodes.begin(), dialogueNodes.end(),
                 [](const DialogueNode& a, const DialogueNode& b) {
                     return a.speaker < b.speaker;
                 });

        return std::lower_bound(dialogueNodes.begin(), dialogueNodes.end(),
                              targetSpeaker,
                              [](const DialogueNode& node, const std::string& target) {
                                  return node.speaker < target;
                              }) - dialogueNodes.begin();
    }

    // 3. Hash-based search - O(1) average complexity
    std::vector<DialogueNode> findDialoguesBySpeaker(const std::string& speaker) {
        std::vector<DialogueNode> result;
        if (speakerIndex.contains(speaker)) {
            for (const std::size_t& index : speakerIndex[speaker]) {
                result.push_back(dialogueNodes[index]);
            }
        }
        return result;
    }
};

#endif