namespace ChordGetter
{
    public partial class MainPage : ContentPage
    {
        private string currentChord = string.Empty;
        public MainPage()
        {
            InitializeComponent();
        }

        private void OnNameTextChanged(object sender, TextChangedEventArgs e)
        {

            SearchButton.IsEnabled = !string.IsNullOrEmpty(currentChord);
        }
        private async void OnSaveClicked(object sender, EventArgs e)
        {
            SearchButton.IsEnabled = false;
            SearchButton.Text = "Searching...";

            var client = new HttpClient();
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                RequestUri = new Uri("https://piano-chords.p.rapidapi.com/chords/e/maj7"),
                Headers =
                    {
                        { "x-rapidapi-key", "a543a6e420msh61b7c51f7104470p1bfeb1jsndcb3730c879b" },
                        { "x-rapidapi-host", "piano-chords.p.rapidapi.com" },
                    },
            };
            using (var response = await client.SendAsync(request))
            {
                response.EnsureSuccessStatusCode();
                var body = await response.Content.ReadAsStringAsync();
                ChordInfo.Text = body;
            }
        }

    }
}
