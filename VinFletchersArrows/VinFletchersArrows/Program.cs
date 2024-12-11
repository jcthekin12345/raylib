
using System.ComponentModel.DataAnnotations;

public enum ArrowHeadType
{
    STEEL,
    WOOD,
    OBSIDIAN,
}

public enum FletchingType
{
    PLASTIC,
    TURKEY_FEATHERS,
    GOOSE_FEATHERS,
}

public class Arrow
{
    
   private (float min, float max) Shaft = (60.0f, 100.0f);
   public ArrowHeadType HeadType { get; set; }
   public FletchingType FletchingType { get; set; }
   
   


}