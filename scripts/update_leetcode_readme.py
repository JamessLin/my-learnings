import os
import re
import requests
import time

LEETCODE_API_URL = "https://leetcode.com/graphql"
QUERY = """
query getQuestionDetail($titleSlug: String!) {
    question(titleSlug: $titleSlug) {
        questionId
        title
        difficulty
        titleSlug
    }
}
"""

def get_problem_details():
    leetcode_dir = 'leetcode'
    problems = []
    
    solution_files = [f for f in os.listdir(leetcode_dir) if f.endswith(('.py', '.java', '.c', '.go'))]

    for filename in solution_files:
        match = re.match(r'(\d+)-(.+?)\.(py|java|c|go)', filename)
        if not match:
            print(f"Skipping file with unexpected name format: {filename}")
            continue
        
        problem_number_str, title_slug, _ = match.groups()

        try:
            response = requests.post(LEETCODE_API_URL, json={'query': QUERY, 'variables': {'titleSlug': title_slug}}, timeout=10)
            response.raise_for_status()
            data = response.json().get('data', {}).get('question')

            if data:
                problems.append({
                    'number': int(data['questionId']),
                    'title': data['title'],
                    'difficulty': data['difficulty'],
                    'url': f"https://leetcode.com/problems/{data['titleSlug']}",
                    'solution_path': filename
                })
            else:
                print(f"No data returned from API for slug: {title_slug}")

        except requests.exceptions.RequestException as e:
            print(f"Error fetching details for {title_slug}: {e}")
        except (KeyError, TypeError) as e:
            print(f"Could not parse API response for {title_slug}: {e}")
        
        time.sleep(1)

    return sorted(problems, key=lambda x: x['number'])

def generate_readme(problems):
    readme_content = "# LeetCode Solutions\n\n"
    readme_content += "A collection of my solutions to LeetCode problems. The table below is automatically generated.\n\n"
    readme_content += "| # | Title | Difficulty | Solution |\n"
    readme_content += "|---|-------|------------|----------|\n"
    
    for problem in problems:
        readme_content += f"| {problem['number']} | [{problem['title']}]({problem['url']}) | {problem['difficulty']} | [Solution](./{problem['solution_path']}) |\n"
        
    with open('leetcode/README.md', 'w', encoding='utf-8') as f:
        f.write(readme_content)

if __name__ == "__main__":
    problems = get_problem_details()
    if problems:
        generate_readme(problems)
        print("LeetCode README.md has been updated successfully.")
    else:
        print("No problems were found or processed. README not updated.") 